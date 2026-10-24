import subprocess
from pathlib import Path


def main():
    programs = [
        "random_encode",
        "random_decode",
        "lcg_encode",
        "lcg_decode",
        "sg_encode",
        "sg_decode",
        "brute_force",
    ]
    print("ENIGMA++")
    for number, name in enumerate(programs, 1):
        print(f"{number}. {name.replace('_', ' ')}")

    choice = input("Choose an option: ")
    if choice not in [str(number) for number in range(1, 8)]:
        print("Invalid option.")
        return
    name = programs[int(choice) - 1]

    folder = Path(__file__).resolve().parent
    build = folder / "build"
    build.mkdir(exist_ok=True)
    program = build / name

    subprocess.run(
        [
            "cc",
            "-std=c11",
            "-Wall",
            "-Wextra",
            "-pedantic",
            str(folder / "c" / f"{name}.c"),
            "-o",
            str(program),
        ],
        check=True,
    )

    subprocess.run([str(program)], check=True)


if __name__ == "__main__":
    main()
