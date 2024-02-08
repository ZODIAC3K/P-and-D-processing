# Matrix Multiplication using multiprocessing

# import numpy as np
# import multiprocessing

# def multiply_row(row, b):
#     return np.dot(row, b)

# if __name__ == "__main__":
#     a = np.array([[1, 2, 3, 13],
#                   [4, 5, 6, 14],
#                   [7, 8, 9, 15],
#                   [10, 11, 12, 16]])

#     b = np.array([10, 20, 30, 40])

#     print("Matrix a =", a)
#     print("Matrix b =", b)

#     pool = multiprocessing.Pool()
#     results = pool.starmap(multiply_row, [(row, b) for row in a])
#     pool.close()
#     pool.join()

#     print("Product of a and b =", results)

# Vector Adition using multiprocessing
    
import numpy as np
import multiprocessing

def add_vectors(a, b):
    return a + b

if __name__ == "__main__":
    a = np.array([1, 2, 3, 4])
    b = np.array([5, 6, 7, 8])

    print("Vector a =", a)
    print("Vector b =", b)

    pool = multiprocessing.Pool()
    result = pool.apply(add_vectors, args=(a, b))
    pool.close()
    pool.join()

    print("Result of vector addition =", result)
