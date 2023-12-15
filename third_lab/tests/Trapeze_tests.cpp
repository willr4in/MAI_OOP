#include <gtest/gtest.h>
#include "../include/figures/Trapeze.hpp"
#include "../src/figures/Trapeze.cpp"


TEST(constructor_test, without_exception_test_1) {
    ASSERT_NO_THROW(Trapeze(Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3)));
}

TEST(constructor_test, without_exception_test_2) {
    ASSERT_NO_THROW(Trapeze(Point(0, 0), Point(5, 0), Point(1,3), Point(3,3)));
}

TEST(constructor_test, with_exception_test_1) {
    ASSERT_THROW(Trapeze(Point(41, 43), Point(13.4, 433.5), Point(40, 0), Point(3, 43)), std::invalid_argument);
}

TEST(constructor_test, with_exception_test_2) {
    ASSERT_THROW(Trapeze(Point(0, 0), Point(1, 0), Point(0, 1), Point(1, 1)), std::invalid_argument);
}

TEST(bottom_top_base_height_test, without_exception_test_1) {
    ASSERT_NO_THROW(Trapeze(5, 2, 1));
}

TEST(bottom_top_base_height_test, without_exception_test_2) {
    ASSERT_NO_THROW(Trapeze(5, 10, 3));
}

TEST(bottom_top_base_height_test, with_exception_test_1) {
    ASSERT_THROW(Trapeze(-5, -2, -1), std::invalid_argument);
}

TEST(bottom_top_base_height_test, with_exception_test_2) {
    ASSERT_THROW(Trapeze(5, 0, -3), std::invalid_argument);
}

TEST(copy_constructor_test, other_trapeze_copy_test) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    Trapeze test_2 (test_1);

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), test_2.get_bottom_base());
    EXPECT_DOUBLE_EQ(test_1.get_top_base(), test_2.get_top_base());
    EXPECT_DOUBLE_EQ(test_1.get_height(), test_2.get_height());
    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), test_2.get_middle_line());
}

TEST(move_constructor_test, other_trapeze_move_test) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    Trapeze test_2 (std::move(test_1));

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), test_2.get_bottom_base());
    EXPECT_DOUBLE_EQ(test_1.get_top_base(), test_2.get_top_base());
    EXPECT_DOUBLE_EQ(test_1.get_height(), test_2.get_height());
    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), test_2.get_middle_line());
}

TEST(assigment_operator_test, copy_assigment_test) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    Trapeze test_2 = test_1;

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), test_2.get_bottom_base());
    EXPECT_DOUBLE_EQ(test_1.get_top_base(), test_2.get_top_base());
    EXPECT_DOUBLE_EQ(test_1.get_height(), test_2.get_height());
    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), test_2.get_middle_line());
}

TEST(assigment_operator_test, move_assigment_test) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    Trapeze test_2 = std::move(test_1);

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), test_2.get_bottom_base());
    EXPECT_DOUBLE_EQ(test_1.get_top_base(), test_2.get_top_base());
    EXPECT_DOUBLE_EQ(test_1.get_height(), test_2.get_height());
    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), test_2.get_middle_line());
}

TEST(calculate_geometric_center_test, calculate_geometric_center_test_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x_cord(), 1.75);
    EXPECT_DOUBLE_EQ(center_test.get_y_cord(), 1.5);
}

TEST(calculate_geometric_center_test, calculate_geometric_center_test_2) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(1,3), Point(3,3));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x_cord(), 2.25);
    EXPECT_DOUBLE_EQ(center_test.get_y_cord(), 1.5);
}

TEST(calculate_perimeter_test, calculate_perimeter_test_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(1,3), Point(3,3));

    EXPECT_DOUBLE_EQ(test_1.calculate_perimeter(), 7 + sqrt(10) + sqrt(13));
}

TEST(calculate_perimeter_test, calculate_perimeter_test_2) {
    Trapeze test_1 (2, 1, 4);

    EXPECT_DOUBLE_EQ(test_1.calculate_perimeter(), 7 + sqrt(17));
}

TEST(calculate_area_test, calculate_area_test_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));

    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 10.5);
}

TEST(calculate_area_test, calculate_area_test_2) {
    Trapeze test_1 (2, 1, 4);

    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 6);
}

TEST(get_bottom_base_test, get_bottom_base_test_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(1,3), Point(3,3));

    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), 5);
}

TEST(get_bottom_base_test, get_bottom_base_test_2) {
    Trapeze test_1 (2, 1, 4);

    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), 2);
}

TEST(get_top_base_test, get_top_base_test_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(1,3), Point(3,3));

    EXPECT_DOUBLE_EQ(test_1.get_top_base(), 2);
}

TEST(get_top_base_test, get_top_base_test_2) {
    Trapeze test_1 (2, 1, 4);

    EXPECT_DOUBLE_EQ(test_1.get_top_base(), 1);
}

TEST(get_height_test, get_height_test_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(1,3), Point(3,3));

    EXPECT_DOUBLE_EQ(test_1.get_height(), 3);
}

TEST(get_height_test, get_height_test_2) {
    Trapeze test_1 (2, 1, 4);

    EXPECT_DOUBLE_EQ(test_1.get_height(), 4);
}

TEST(get_middle_line_test, get_middle_line_test_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(1,3), Point(3,3));

    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), 3.5);
}

TEST(get_middle_line_test, get_middle_line_test_2) {
    Trapeze test_1 (2, 1, 4);

    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), 1.5);
}

TEST(operator_double_test, operator_double_test_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    double operator_double_test_val = double(test_1);

    EXPECT_DOUBLE_EQ(operator_double_test_val, 10.5);
}

TEST(operator_double_test, operator_double_test_2) {
    Trapeze test_1 (2, 1, 4);
    double operator_double_test_val = double(test_1);

    EXPECT_DOUBLE_EQ(operator_double_test_val, 6);
}

TEST(equal_operator_test, true_return_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    Trapeze test_2 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));

    EXPECT_TRUE(test_1 == test_2);
}

TEST(equal_operator_test, true_return_2) {
    Trapeze test_1 (2, 1, 4);
    Trapeze test_2 (2, 1, 4);

    EXPECT_TRUE(test_1 == test_2);
}

TEST(equal_operator_test, false_return_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    Trapeze test_2 (Point(0, 0), Point(5, 0), Point(1,3), Point(2, 3));

    EXPECT_FALSE(test_1 == test_2);
}

TEST(equal_operator_test, false_return_2) {
    Trapeze test_1 (2, 1, 4);
    Trapeze test_2 (2, 5, 3);

    EXPECT_FALSE(test_1 == test_2);
}

TEST(non_equal_operator_test, true_return_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    Trapeze test_2 (Point(0, 0), Point(5, 0), Point(1,3), Point(2, 3));

    EXPECT_TRUE(test_1 != test_2);
}

TEST(non_equal_operator_test, true_return_2) {
    Trapeze test_1 (2, 1, 4);
    Trapeze test_2 (2, 5, 3);

    EXPECT_TRUE(test_1 != test_2);
}

TEST(non_equal_operator_test, false_return_1) {
    Trapeze test_1 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));
    Trapeze test_2 (Point(0, 0), Point(5, 0), Point(0,3), Point(2, 3));

    EXPECT_FALSE(test_1 != test_2);
}

TEST(non_equal_operator_test, false_return_2) {
    Trapeze test_1 (2, 1, 4);
    Trapeze test_2 (2, 1, 4);

    EXPECT_FALSE(test_1 != test_2);
}

TEST(rotated_trapeze_tests, constructor_test_without_exception) {
    ASSERT_NO_THROW(Trapeze(Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2)));
}

TEST(rotated_trapeze_tests, copy_constructor_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));
    Trapeze test_2 (test_1);

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), test_2.get_bottom_base());
    EXPECT_DOUBLE_EQ(test_1.get_top_base(), test_2.get_top_base());
    EXPECT_DOUBLE_EQ(test_1.get_height(), test_2.get_height());
    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), test_2.get_middle_line());
}

TEST(rotated_trapeze_tests, move_constructor_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));
    Trapeze test_2 (std::move(test_1));

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), test_2.get_bottom_base());
    EXPECT_DOUBLE_EQ(test_1.get_top_base(), test_2.get_top_base());
    EXPECT_DOUBLE_EQ(test_1.get_height(), test_2.get_height());
    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), test_2.get_middle_line());
}

TEST(rotated_trapeze_tests, assigment_operator_copy_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));
    Trapeze test_2 = test_1;

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), test_2.get_bottom_base());
    EXPECT_DOUBLE_EQ(test_1.get_top_base(), test_2.get_top_base());
    EXPECT_DOUBLE_EQ(test_1.get_height(), test_2.get_height());
    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), test_2.get_middle_line());
}

TEST(rotated_trapeze_tests, assigment_operator_move_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));
    Trapeze test_2 = std::move(test_1);

    EXPECT_TRUE(test_1 == test_2);
    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), test_2.get_bottom_base());
    EXPECT_DOUBLE_EQ(test_1.get_top_base(), test_2.get_top_base());
    EXPECT_DOUBLE_EQ(test_1.get_height(), test_2.get_height());
    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), test_2.get_middle_line());
}

TEST(rotated_trapeze_tests, calculate_geometric_center_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));
    Point center_test = test_1.calculate_geometric_center();

    EXPECT_DOUBLE_EQ(center_test.get_x_cord(), 2.25);
    EXPECT_DOUBLE_EQ(center_test.get_y_cord(), 2.25);
}

TEST(rotated_square_tests, calculate_perimeter_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));

    EXPECT_DOUBLE_EQ(test_1.calculate_perimeter(), 2* sqrt(5) + sqrt(8) + sqrt(2));
}

TEST(rotated_square_tests, calculate_area_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));

    EXPECT_DOUBLE_EQ(test_1.calculate_area(), 3);
}

TEST(rotated_square_tests, get_bottom_base_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));

    EXPECT_DOUBLE_EQ(test_1.get_bottom_base(), sqrt(2));
}

TEST(rotated_square_tests, get_top_base_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));

    EXPECT_DOUBLE_EQ(test_1.get_top_base(), sqrt(8));
}

TEST(rotated_square_tests, get_height_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));

    EXPECT_DOUBLE_EQ(test_1.get_height(), sqrt(2));
}

TEST(rotated_square_tests, get_middle_line_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));

    EXPECT_DOUBLE_EQ(test_1.get_middle_line(), (sqrt(2) + sqrt(8)) / 2);
}

TEST(rotated_square_tests, operator_double_test) {
    Trapeze test_1 (Point(1, 2), Point(2, 1), Point(2,4), Point(4, 2));
    double operator_double_test_val = double(test_1);

    EXPECT_DOUBLE_EQ(operator_double_test_val, 3);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
