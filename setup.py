import os
import re
import subprocess
import sys
from pathlib import Path
from setuptools import (
    Extension,
    setup,
)
from setuptools.command.build_ext import (
    build_ext,
)


class CMakeExtension(Extension):
    def __init__(
        self,
        name: str,
        sourcedir: str = "",
    ) -> None:
        super().__init__(name, sources=[])
        self.sourcedir = os.fspath(Path(sourcedir).resolve())


class CMakeBuild(build_ext):
    def build_extension(
        self,
        ext: CMakeExtension,
    ) -> None:
        ext_fullpath = Path.cwd() / self.get_ext_fullpath(ext.name)
        extdir = ext_fullpath.parent.resolve()

        cfg = "Debug" if int(os.environ.get("DEBUG", 0)) else "Release"

        cmake_args = [
            f"-DCMAKE_LIBRARY_OUTPUT_DIRECTORY={extdir}{os.sep}",
            f"-DPYTHON_EXECUTABLE={sys.executable}",
            f"-DCMAKE_BUILD_TYPE={cfg}",
        ]

        build_args = []

        if sys.platform.startswith("darwin"):
            # macOS specific configurations can be added here if necessary
            # For example, handling architectures:
            archs = re.findall(
                r"-arch (\S+)",
                os.environ.get(
                    "ARCHFLAGS",
                    "",
                ),
            )
            if archs:
                cmake_args += [f"-DCMAKE_OSX_ARCHITECTURES={';'.join(archs)}"]

        build_temp = Path(self.build_temp) / ext.name
        if not build_temp.exists():
            build_temp.mkdir(parents=True)

        subprocess.run(
            [
                "cmake",
                ext.sourcedir,
                *cmake_args,
            ],
            cwd=build_temp,
            check=True,
        )
        subprocess.run(
            [
                "cmake",
                "--build",
                ".",
                *build_args,
            ],
            cwd=build_temp,
            check=True,
        )


setup(
    name="damidoumPyML",
    version="0.0.1",
    author="Damidoum",
    url="https://github.com/Damidoum/DamidoumML",
    author_email="damien.rouchouse@etu.minesparis.psl.eu",
    description="A personal machine learning library to learn cpp,"
    "cmake and python packaging.",
    long_description="",
    licence="MIT",
    ext_modules=[CMakeExtension("damidoumPyML")],
    cmdclass={"build_ext": CMakeBuild},
    zip_safe=False,
    python_requires=">=3.12",
)
