class HashTable:
    hash_table = []
    m = int(input("Enter The Size Of Hash Table:"))

    def initialize(self):
        for i in range(self.m):
            self.hash_table.append(0)

    def hash_function(self, item):
        key = item % self.m
        return key

    def linear(self, arr):
        for i in range(len(arr)):
            key = self.hash_function(arr[i])
            while (self.hash_table[key] != 0):
                key = (key + 1) % self.m
            self.hash_table[key] = arr[i]

    def quadratic(self, arr):
        for i in range(len(arr)):
            key = self.hash_function(arr[i])
            if (self.hash_table[key] != 0):
                for j in range(self.m):
                    key = (key + (i * i)) % self.m
                    if (self.hash_table[key] == 0):
                        break
            self.hash_table[key] = arr[i]

    def display(self):
        for i in range(self.m):
            print(i, '->', self.hash_table[i])


table = HashTable()
table.initialize()
a = 1
n = int(input("Enter The Number Of Telephone Numbers To Store In Hash Table:"))
tele = []
for i in range(n):
    tele_no = int(input("Enter Telephone Number :"))
    tele.append(tele_no)
while (a == 1):
    print("Choose The Method Of Resolution \n 1.linear Probing \n 2.Quadratic Probing \n 3.Exit")
    c = int(input())
    if (c == 1):
        table.linear(tele)
        table.display()
    if (c == 2):
        table.quadratic(tele)
        table.display()
    if (c == 3):
        print("Thank You")
        a = 0
        break



