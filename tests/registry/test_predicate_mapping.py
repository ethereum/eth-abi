import functools
import operator
import pytest

from eth_abi.registry import (
    PredicateMapping,
    Equals,
)


@pytest.fixture
def mapping():
    return PredicateMapping('registry')


equals_foo = Equals('foo')
equals_bar = Equals('bar')


def test_can_add_predicates_and_find_corresponding_values(mapping):
    mapping.add(equals_foo, 'foo value')
    mapping.add(equals_bar, 'bar value')

    assert mapping.find('foo') == 'foo value'
    assert mapping.find('bar') == 'bar value'


def test_cannot_add_same_predicate_twice(mapping):
    mapping.add(equals_foo, 'foo value')

    pattern = r'Matcher .* already exists in registry'
    with pytest.raises(ValueError, match=pattern):
        mapping.add(equals_foo, 'foo value')


def test_cannot_add_two_predicates_with_same_label(mapping):
    mapping.add(equals_foo, 'foo value', 'some label')

    pattern = r"Matcher .* with label 'some label' already exists in registry"
    with pytest.raises(ValueError, match=pattern):
        mapping.add(equals_bar, 'bar value', 'some label')


def test_no_matching_predicates_should_raise_error(mapping):
    mapping.add(equals_foo, 'foo value')
    mapping.add(equals_bar, 'bar value')

    with pytest.raises(ValueError, match=r"No matching entries for 'baz' in registry"):
        mapping.find('baz')


def test_multiple_matching_predicates_should_raise_error(mapping):
    mapping.add(Equals('baz'), 'baz value')
    mapping.add(functools.partial(operator.eq, 'baz'), 'baz value')

    with pytest.raises(ValueError) as e:
        mapping.find('baz')

    e.match(r"Multiple matching entries for 'baz' in registry")
    e.match(r"<Equals \(== 'baz'\)>")
    e.match(r'functools\.partial')


def test_can_remove_predicates_by_reference(mapping):
    mapping.add(equals_foo, 'foo value')
    assert mapping.find('foo') == 'foo value'

    mapping.remove(equals_foo)
    with pytest.raises(ValueError, match=r'No matching'):
        mapping.find('foo')


def test_removing_non_existent_predicate_raises_error(mapping):
    with pytest.raises(KeyError, match=r'Matcher .* not found in registry'):
        mapping.remove(equals_foo)


def test_removing_labeled_predicate_by_reference_also_removes_label(mapping):
    mapping.add(equals_foo, 'foo value', 'foo label')
    mapping.remove(equals_foo)

    # Just a bit of white-box testing here
    assert len(mapping._values) == 0
    assert len(mapping._labeled_predicates) == 0


def test_can_remove_predicates_by_label_if_label_was_given(mapping):
    mapping.add(equals_foo, 'foo value', 'foo label')
    assert mapping.find('foo') == 'foo value'

    mapping.remove('foo label')
    with pytest.raises(ValueError, match=r'No matching'):
        mapping.find('foo')


def test_removing_non_existent_label_raises_error(mapping):
    with pytest.raises(KeyError, match=r"Label 'asdf' not found in registry"):
        mapping.remove('asdf')


def test_removing_unsupported_type_raises_error(mapping):
    with pytest.raises(TypeError, match=r'must be callable or string.*got <class \'bool\'>'):
        mapping.remove(True)
