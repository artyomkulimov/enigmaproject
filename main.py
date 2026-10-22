import subprocess
from pathlib import Path


def main():
    folder = Path(__file__).resolve().parent
    build = folder / "build"
    build.mkdir(exist_ok=True)
    program = build / "enigma"

    subprocess.run(
        [
            "cc",
            "-std=c11",
            "-Wall",
            "-Wextra",
            "-pedantic",
            str(folder / "c" / "main.c"),
            "-o",
            str(program),
        ],
        check=True,
    )

    result = subprocess.run([str(program)], capture_output=True, text=True, check=True)
    print("ENIGMA++")
    print(result.stdout, end="")


if __name__ == "__main__":
    main()
