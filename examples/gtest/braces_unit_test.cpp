#include <gtest/gtest.h>
#include "brace_validation.h"

// Unit tests to check if brace validator works properly

TEST(ValidString, EmptyString) {
	EXPECT_TRUE(checkValidity(""));
}

TEST(ValidString, Valid1) {
	EXPECT_TRUE(checkValidity("()"));
}

TEST(ValidString, Valid2) {
	EXPECT_TRUE(checkValidity("()()"));
}

TEST(ValidString, Valid3) {
	EXPECT_TRUE(checkValidity("(())"));
}

TEST(ValidString, Valid4) {
	EXPECT_TRUE(checkValidity("()(())"));
}

TEST(InvalidString, Invalid1) {
	EXPECT_FALSE(checkValidity("("));
}

TEST(InvalidString, Invalid2) {
	EXPECT_FALSE(checkValidity(")"));
}

TEST(InvalidString, Invalid3) {
	EXPECT_FALSE(checkValidity(")("));
}

TEST(InvalidString, Invalid4) {
	EXPECT_FALSE(checkValidity("()("));
}

TEST(InvalidString, Invalid5) {
	EXPECT_FALSE(checkValidity("(()"));
}

TEST(InvalidString, Invalid6) {
	EXPECT_FALSE(checkValidity("())"));
}
