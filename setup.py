#!/usr/bin/env python
# -*- coding: utf-8 -*-
from setuptools import (
    setup,
    find_packages,
)

HYPOTHESIS_REQUIREMENT = "hypothesis>=4.18.2,<5.0.0"

extras_require = {
    'tools': [
        HYPOTHESIS_REQUIREMENT,
    ],
    'test': [
        "pytest>=6.2.5,<7",
        "pytest-pythonpath>=0.7.1",
        "pytest-xdist>=2.5.0,<3",
        "tox>=2.9.1,<3",
        "eth-hash[pycryptodome]",
        HYPOTHESIS_REQUIREMENT,
    ],
    'lint': [
        "flake8==4.0.1",
        "isort>=4.2.15,<5",
        "mypy==0.910",
        "pydocstyle>=3.0.0,<4",
    ],
    'doc': [
        "Sphinx>=1.6.5,<2",
        "jinja2>=3.0.0,<3.1.0",  # jinja2<3.0 or >=3.1.0 cause doc build failures.
        "sphinx_rtd_theme>=0.1.9",
        "towncrier==18.5.0",  # towncrier doesn't follow semver
    ],
    'dev': [
        "bumpversion>=0.5.3,<1",
        "pytest-watch>=4.1.0,<5",
        "wheel",
        "twine",
        "ipython",
    ],
}

extras_require['dev'] = (
    extras_require['dev'] +  # noqa: W504
    extras_require['test'] +  # noqa: W504
    extras_require['lint'] +  # noqa: W504
    extras_require['doc']
)


with open('./README.md') as readme:
    long_description = readme.read()


setup(
    name='eth_abi',
    # *IMPORTANT*: Don't manually change the version here. Use `make bump`, as described in readme
    version='3.0.0',
    description="""eth_abi: Python utilities for working with Ethereum ABI definitions, especially encoding and decoding""",
    long_description=long_description,
    long_description_content_type='text/markdown',
    author='The Ethereum Foundation',
    author_email='snakecharmers@ethereum.org',
    url='https://github.com/ethereum/eth-abi',
    include_package_data=True,
    install_requires=[
        'eth-utils>=2.0.0,<3.0.0',
        'eth-typing>=3.0.0,<4.0.0',
        'parsimonious>=0.8.0,<0.9.0',
    ],
    python_requires='>=3.7, <4',
    extras_require=extras_require,
    py_modules=['eth_abi'],
    license="MIT",
    zip_safe=False,
    keywords='ethereum',
    packages=find_packages(exclude=["tests", "tests.*"]),
    package_data={'eth_abi': ['py.typed']},
    classifiers=[
        'Development Status :: 5 - Production/Stable',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Natural Language :: English',
        'Programming Language :: Python :: 3',
        'Programming Language :: Python :: 3.7',
        'Programming Language :: Python :: 3.8',
        'Programming Language :: Python :: 3.9',
        'Programming Language :: Python :: 3.10',
    ],
)
