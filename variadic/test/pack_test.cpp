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

// Struct to test perfect-forwarding of the concatenation functions.
// No other constructor but the default should be called.
template <char C>
struct Forwardable {
    explicit Forwardable(int value) : value_(value) {}

    Forwardable(Forwardable<C> const&) = delete;

    Forwardable(Forwardable<C>&&) = delete;

    Forwardable<C>& operator=(Forwardable<C> const&) = delete;

    Forwardable<C>& operator=(Forwardable<C>&&) = delete;

    int value_;
};

template <char C>
std::ostream& operator<<(std::ostream& out, Forwardable<C> const& fwd) {
    return out << C << fwd.value_;
}

TEST(PackTest, concatPerfectForwarding) {
    Forwardable<'A'> a(1);
    Forwardable<'B'> b(2);
    ASSERT_EQ(concat(a, b), "A1B2");
}

TEST(PackTest, concatReversePerfectForwarding) {
    Forwardable<'A'> a(1);
    Forwardable<'B'> b(2);
    ASSERT_EQ(concatReverse(a, b), "B2A1");
}

} // namespace test
} // namespace study
