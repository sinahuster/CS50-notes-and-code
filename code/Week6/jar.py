def main():
    jar = Jar()
    print(str(jar.capacity))
    print(str(jar))
    jar.deposit(6)
    print(str(jar))
    jar.withdraw(4)
    print(str(jar))


class Jar:
    def __init__(self, capacity=12):
        if capacity < 1:
            raise ValueError
        self._capacity = capacity
        self._size = 0

    def __str__(self):
        return "🍪" * self._size

    def deposit(self, n):
        if n < 1 or (n + self._size) > self._capacity:
            raise ValueError
        self._size += n

    def withdraw(self, n):
        if n < 1 or (self._size - n) < 0:
            raise ValueError
        self._size -= n

    @property
    def capacity(self):
        return self._capacity

    @property
    def size(self):
        return self._size


main()
