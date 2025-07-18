import subprocess

PROGRAM_NAME = "./lpc"

def test(input: str, output: str) -> bool:
    testPassed: bool = False

    process = subprocess.run(
        [PROGRAM_NAME],
        input=input,
        text=True,
        capture_output=True
    )

    if process.stdout == output:
        testPassed = True

    return testPassed

inputs: list[str] = [
"""
1
""",
"""
2
"""
]

outputs: list[str] = [
"""
hola
""",
"""
mundo
"""
]

def main():
    if len(outputs) != len(inputs):
        print("el numero de entradas y salidas no concuerdan")
        return
    
    i = 0
    allPassed: bool = True
    for input, output in zip(inputs, outputs):
        input = input.lstrip("\n")
        output = output.strip("\n")

        print(f"test {i} -> ", end="")
        if not test(input, output):
            print("\033[31mnot passed :(\033[0m")
            allPassed = False
        else:    
            print ("\033[32mpassed :)\033[0m")

        i += 1

    if allPassed:
        print("All fine :), remember to use -O3 and -s")
    else:
        print("give a better try body")
    
main()