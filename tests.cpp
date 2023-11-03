#include <gtest/gtest.h>
#include "hex.hpp"

TEST(constructor, basic) {
    Hex test_subject = Hex();
    ASSERT_EQ(test_subject.get_string_for_view(), "");
}

TEST(constructor, chars) {
    Hex test_subject = Hex(5, '1');
    ASSERT_EQ(test_subject.get_string_for_view(), "11111");
}

TEST(constructor, char_exception) {
    ASSERT_THROW(Hex(5, 'M'), std::invalid_argument);
}

TEST(constructor, init_list) {
    Hex test_subject = Hex({'1','2','3','A'});
    ASSERT_EQ(test_subject.get_string_for_view(), "123A");
}

TEST(constructor, init_list_exception) {
    ASSERT_THROW(Hex({'M','N','O'}), std::invalid_argument);
}

TEST(constructor, string) {
    Hex test_subject = Hex("ABE309");
    ASSERT_EQ(test_subject.get_string_for_view(), "ABE309");
}

TEST(constructor, string_exception) {
    ASSERT_THROW(Hex("TL"), std::invalid_argument);
}

TEST(constructor, copying_1) {
    Hex test_subject_1 = Hex("E1BA");
    Hex test_subject_2 = Hex(test_subject_1);
    ASSERT_EQ(test_subject_2.get_string_for_view(), "E1BA");
}

TEST(constructor, copying_2) {
    Hex test_subject = Hex(Hex("E1BA"));
    ASSERT_EQ(test_subject.get_string_for_view(), "E1BA");
}

TEST(destructor, basic) {
    Hex test_subject = Hex("E1BA");
    test_subject.~Hex();
    ASSERT_EQ(test_subject.get_string_for_view(), "");
}

TEST(bool_ops, bigger_1) {
    Hex test_subject_1 = Hex("541");
    Hex test_subject_2 = Hex("540");
    ASSERT_TRUE(test_subject_1 > test_subject_2);
}

TEST(bool_ops, bigger_2) {
    Hex test_subject_1 = Hex("540");
    Hex test_subject_2 = Hex("540");
    ASSERT_FALSE(test_subject_1 > test_subject_2);
}

TEST(bool_ops, less) {
    Hex test_subject_1 = Hex("0");
    Hex test_subject_2 = Hex("F");
    ASSERT_TRUE(test_subject_1 < test_subject_2);
}

TEST(bool_ops, equal) {
    Hex test_subject_1 = Hex("E");
    Hex test_subject_2 = Hex("E");
    ASSERT_TRUE(test_subject_1 == test_subject_2);
}

TEST(math_ops, assignment) {
    Hex test_subject_1 = Hex("BAB");
    Hex test_subject_2 = test_subject_1;
    ASSERT_EQ(test_subject_2.get_string_for_view(), "BAB");
}

TEST(math_ops, plus_1) {
    Hex test_subject_1 = Hex("9");
    Hex test_subject_2 = Hex("1");
    ASSERT_EQ((test_subject_1 + test_subject_2).get_string_for_view(), "A");
}

TEST(math_ops, plus_2) {
    Hex test_subject_1 = Hex("8AB");
    Hex test_subject_2 = Hex("B7B");
    ASSERT_EQ((test_subject_1 + test_subject_2).get_string_for_view(), "1426");
}

TEST(math_ops, plus_3) {
    Hex test_subject_1 = Hex("0");
    Hex test_subject_2 = Hex("0");
    ASSERT_EQ((test_subject_1 + test_subject_2).get_string_for_view(), "0");
}

TEST(math_ops, plus_4) {
    Hex test_subject_1 = Hex("ABC123");
    Hex test_subject_2 = Hex("CCC8E");
    ASSERT_EQ((test_subject_1 + test_subject_2).get_string_for_view(), "B88DB1");
}

TEST(math_ops, minus_1) {
    Hex test_subject_1 = Hex("E82");
    Hex test_subject_2 = Hex("12D");
    ASSERT_EQ((test_subject_1 - test_subject_2).get_string_for_view(), "D55");
}

TEST(math_ops, minus_2) {
    Hex test_subject_1 = Hex("E82");
    Hex test_subject_2 = Hex("DDA");
    ASSERT_EQ((test_subject_1 - test_subject_2).get_string_for_view(), "A8");
}

TEST(math_ops, minus_3) {
    Hex test_subject_1 = Hex("DDA");
    Hex test_subject_2 = Hex("DD8");
    ASSERT_EQ((test_subject_1 - test_subject_2).get_string_for_view(), "2");
}

TEST(math_ops, minus_4) {
    Hex test_subject_1 = Hex("ABC123");
    Hex test_subject_2 = Hex("CCC8E");
    ASSERT_EQ((test_subject_1 - test_subject_2).get_string_for_view(), "9EF495");
}

TEST(math_ops, minus_5) {
    Hex test_subject_1 = Hex("ABEF");
    Hex test_subject_2 = Hex("7EA");
    ASSERT_EQ((test_subject_1 - test_subject_2).get_string_for_view(), "A405");
}

TEST(math_ops, minus_6) {
    Hex test_subject_1 = Hex("ABB");
    Hex test_subject_2 = Hex("ABB");
    ASSERT_EQ((test_subject_1 - test_subject_2).get_string_for_view(), "0");
}

TEST(math_ops, minus_exception_1) {
    Hex test_subject_1 = Hex("12");
    Hex test_subject_2 = Hex("DDD");
    ASSERT_THROW(test_subject_1-test_subject_2, std::invalid_argument);
}

TEST(math_ops, minus_exception_2) {
    Hex test_subject_1 = Hex("1");
    Hex test_subject_2 = Hex("2");
    ASSERT_THROW(test_subject_1-test_subject_2, std::invalid_argument);
}