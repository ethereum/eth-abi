#!/usr/bin/env python
# -*- coding: utf-8 -*-
import os

from setuptools import setup


DIR = os.path.dirname(os.path.abspath(__file__))

version = '0.2.2'

readme = open(os.path.join(DIR, 'README.md')).read()


setup(
    name='ethereum-abi-utils',
    version=version,
    description="""Ethereum ABI Utils""",
    long_description=readme,
    author='Piper Merriam',
    author_email='pipermerriam@gmail.com',
    url='https://github.com/pipermerriam/ethereum-abi-utils',
    include_package_data=True,
    install_requires=[
        'rlp>=0.4.6',
    ],
    py_modules=['eth_abi'],
    license="MIT",
    zip_safe=False,
    keywords='ethereum',
    packages=[
        "eth_abi",
    ],
    classifiers=[
        'Development Status :: 2 - Pre-Alpha',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: BSD License',
        'Natural Language :: English',
        'Programming Language :: Python :: 2',
        'Programming Language :: Python :: 2.7',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.3',
        'Programming Language :: Python :: 3.4',
    ],
)
