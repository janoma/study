#include <variadic/pack.h>

#include <tuple>

#include <gtest/gtest.h>

namespace study {
namespace test {

TEST(PackTest, zeroSizePack) {
    ASSERT_EQ(sizeOfPack(), 0);
}

TEST(PackTest, packOfVoid) {
    ASSERT_EQ(sizeOfPack<void>(), 1);
}

TEST(PackTest, packOfSizeTwo) {
    // most-vexing parse
    ASSERT_EQ((sizeOfPack<std::int32_t, char>()), 2);
}

TEST(PackTest, packOfTuple) {
    // most-vexing parse
    ASSERT_EQ((sizeOfPack<std::tuple<char, bool, int>>()), 1);
}

TEST(PackTest, concatEmptyPack) {
    ASSERT_EQ(concat(), "");
}

TEST(PackTest, concatOneInt) {
    ASSERT_EQ(concat(42), "42");
}

TEST(PackTest, concatTwoInts) {
    ASSERT_EQ(concat(4, 2), "42");
}

TEST(PackTest, concatIntAndEmptyString) {
    ASSERT_EQ(concat(42, ""), "42");
}

TEST(PackTest, concatIntsAndChar) {
    ASSERT_EQ(concat(4, 2, 'c'), "42c");
}

TEST(PackTest, concatCharAndBool) {
    // Requires std::boolalpha in the implementation
    ASSERT_EQ(concat('c', true), "ctrue");
}

TEST(PackTest, concatReverseEmptyPack) {
    ASSERT_EQ(concatReverse(), "");
}

TEST(PackTest, concatReverseOneElement) {
    ASSERT_EQ(concatReverse(42), "42");
}

TEST(PackTest, concatReverseTwoElements) {
    ASSERT_EQ(concatReverse(4, 'a'), "a4");
}

TEST(PackTest, concatReverseThreeElements) {
    ASSERT_EQ(concatReverse(4, 'a', false), "falsea4");
}

} // namespace test
} // namespace study
