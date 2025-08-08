def test_import_and_version():
    import faster_eth_abi

    assert isinstance(faster_eth_abi.__version__, str)
