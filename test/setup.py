from pybind11.setup_helpers import Pybind11Extension, build_ext
from setuptools import setup

__version__ = "0.0.1"

ext_modules = [
    Pybind11Extension("addition_test",
    ["test_add.cpp"],
    define_macros = [("VERSION_INFO", __version__)]
    )
]

setup(
    name="addition_example",
    version=__version__,
    author="manas",
    description="Pybind11 test module to add two numbers",
    ext_modules=ext_modules,
    zip_safe=False,
    python_requires=">=3.8"
)
