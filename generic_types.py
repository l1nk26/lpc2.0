def isInFile(pattern: str, fileName: str):
    isIn = False
    with open(fileName, "r") as f:
        for line in f.readlines():
            if pattern in line:
                isIn = True
                break

    return isIn


def getTemplateTypesOf(className: str, fileName: str = "main.cpp") -> list[str]:
    types = []
    with open(fileName, "r") as f:
        for line in f.readlines():
            if className + "<" not in line or "<" + className in line:
                continue
            type = line[line.find("<")+1:line.rfind(">")]
            types.append(type)
            
    return types

def handAnidateTemplates(types: list[str]) -> list[str]:
    processedTemplates = []

    for type in types:
        if type.find("<") == -1:
            continue
        
        newType = type[type.find("<")+1:type.rfind(">")]
        processedTemplates.append(newType)

        if newType.find("<") > -1:
            processedTemplates.extend(handAnidateTemplates(processedTemplates))

    return processedTemplates

for className in ("List", "Stack", "Queue"):

    types = getTemplateTypesOf(className)

    types.extend(handAnidateTemplates(types))

    types.sort(key=lambda x: x.count("<"))

    fileName = f"lpc/{className}.cpp"
    for type in types:
        line = f"template class {className}<{type}>"
        if isInFile(line, fileName):
            continue

        with open(fileName, "a") as f:
            f.write(line)


