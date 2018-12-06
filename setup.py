#!/usr/bin/env python
# -*- coding: utf-8 -*-
from setuptools import (
    setup,
    find_packages,
)


setup(
    name='eth-abi',
    # *IMPORTANT*: Don't manually change the version here. Use the 'bumpversion' utility.
    version='1.3.0',
    description="""Ethereum ABI Utils""",
    long_description_markdown_filename='README.md',
    author='Piper Merriam',
    author_email='pipermerriam@gmail.com',
    url='https://github.com/ethereum/eth-abi',
    include_package_data=True,
    install_requires=[
        'eth-utils>=1.2.0,<2.0.0',
        'eth-typing>=2.0.0,<3.0.0',
        'parsimonious>=0.8.0,<0.9.0',
    ],
    extras_require={
        'doc': [
            "Sphinx>=1.6.5,<2",
            "sphinx_rtd_theme>=0.1.9",
        ],
    },
    setup_requires=['setuptools-markdown'],
    py_modules=['eth_abi'],
    license="MIT",
    zip_safe=False,
    keywords='ethereum',
    packages=find_packages(exclude=["tests", "tests.*"]),
    package_data={'eth_abi': ['py.typed']},
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Natural Language :: English',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.5',
        'Programming Language :: Python :: 3.6',
        'Programming Language :: Python :: Implementation :: PyPy',
    ],
)
