def test_import_and_version():
    import eth_abi

    assert isinstance(eth_abi.__version__, str)
