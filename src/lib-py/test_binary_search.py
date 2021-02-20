import unittest
from binary_search import bisect_left, bisect_right, bisect_element_index_search, bisect_square_search

class BisectLeftTest(unittest.TestCase):
    def setUp(self):
        self.arr = [1, 2, 3, 4, 4, 4, 5, 7, 8]

    def tearDown(self):
        pass

    def test_over_left(self):
        self.assertEqual(0, bisect_left(self.arr, -1))

    def test_stop_even(self):
        self.assertEqual(1, bisect_left(self.arr, 2))

    def test_stop_odd(self):
        self.assertEqual(2, bisect_left(self.arr, 3))

    def test_stop_block(self):
        self.assertEqual(3, bisect_left(self.arr, 4))

    def test_over_right(self):
        self.assertEqual(9, bisect_left(self.arr, 9))

    def test_not_exist(self):
        self.assertEqual(7, bisect_left(self.arr, 6))


class BisectRightTest(unittest.TestCase):
    def setUp(self):
        self.arr = [1, 2, 3, 4, 4, 4, 5, 7, 8]

    def tearDown(self):
        pass

    def test_over_left(self):
        self.assertEqual(0, bisect_right(self.arr, -1))

    def test_stop_even(self):
        self.assertEqual(2, bisect_right(self.arr, 2))

    def test_stop_odd(self):
        self.assertEqual(3, bisect_right(self.arr, 3))

    def test_stop_block(self):
        self.assertEqual(6, bisect_right(self.arr, 4))

    def test_over_right(self):
        self.assertEqual(9, bisect_right(self.arr, 9))

    def test_not_exist(self):
        self.assertEqual(7, bisect_right(self.arr, 6))

class BinaryIndexSearchTest(unittest.TestCase):
    def setUp(self):
        self.arr = [1, 2, 5, 7, 8]

    def tearDown(self):
        pass

    def test_over_left(self):
        self.assertEqual(-1, bisect_element_index_search(self.arr, -1))

    def test_over_right(self):
        self.assertEqual(-1, bisect_element_index_search(self.arr, 9))

    def test_leftmost_exist(self):
        self.assertEqual(0, bisect_element_index_search(self.arr, 1))

    def test_mid_exist(self):
        self.assertEqual(2, bisect_element_index_search(self.arr, 5))

    def test_rightmost_exist(self):
        self.assertEqual(4, bisect_element_index_search(self.arr, 8))

    def test_not_exist(self):
        self.assertEqual(-1, bisect_element_index_search(self.arr, 3))


class BinarySquareSearchTest(unittest.TestCase):
    def setUp(self):
        pass

    def tearDown(self):
        pass

    # def test_just_exist(self):
    #     self.assertEqual(5, bisect_square_search(25))

    # def test_over_left(self):
    #     self.assertEqual(4, bisect_square_search(24))

    # def test_over_right(self):
    #     self.assertEqual(5, bisect_square_search(26))

    # def test_over_right(self):
    #     self.assertEqual(3, bisect_square_search(13))
    def test(self):
        import math
        for i in range(101):
            x = math.sqrt(i)
            self.assertEqual(int(x), bisect_square_search(i))

    # def test_over_right(self):
    #     self.assertEqual(-1, bisect_element_index_search(self.arr, 9))

    # def test_leftmost_exist(self):
    #     self.assertEqual(0, bisect_element_index_search(self.arr, 1))

    # def test_mid_exist(self):
    #     self.assertEqual(2, bisect_element_index_search(self.arr, 5))

    # def test_rightmost_exist(self):
    #     self.assertEqual(4, bisect_element_index_search(self.arr, 8))

    # def test_not_exist(self):
    #     self.assertEqual(-1, bisect_element_index_search(self.arr, 3))

if __name__ == "__main__":
    unittest.main()
