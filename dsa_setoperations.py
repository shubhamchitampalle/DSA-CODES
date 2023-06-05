s1 = []
s2 = []
u = []

class set():
    def insertion(self, a):
        print("Insersion in set : ")
        self.n = int(input("no of elements in set : "))
        for i in range(self.n):
            ele = int(input("enter elements in a set : "))
            a.append(ele)

    def display(self, s):
        str1 = ""
        for i in s:
            str1 += str(i)
            str1 = str1 + ','
        print("set={", end="")
        print(str1[0:len(str1) - 1], end="")
        print("}")

    def search(self, s):
        x = int(input("enter element that you want to search in 1st: "))
        if x in s:
            print(x, " found ")
        else:
            print(x, " not found ")

    def size(self, s):
        a = len(s)
        print("size of set 1 is : ", a)

    def deletion(self, s):
        a = int(input("enter element which you want to delete from 1st :"))
        if a in s:
            s.remove(a)
            print("element deleted ")
        else:
            print("not found ")

    def union(self, x):
        for i in s1:
            if i in s2:
                x.remove(i)

    def intersection(self, y):
        for i in s1:
            if i in s2:
                y.append(i)

    def difference(self, q):
        print("1st set minus 2nd set :")
        for i in s1:
            if i in s2:
                q.remove(i)

    def subset(self):
        flag1=0
        for a in s1:
            if a not in s2:
                print("s1 is not the subset of s2...")
                flag1=1
                break
        if flag1==0:
            print("s1 is subset of s2...")

        flag2=0
        for b in s2:
            if b not in s1:
                print("s2 is not the subset of s1...")
                flag2=1
                break
        if flag2==0:
            print("s2 is subset of s1...")

def main():
    obj = set()
    print(
        "1)Insert 1st set\n2)Insert 2nd set\n3)Remove\n4)Search\n5)size\n6)Intersection\n7)Union\n8)Difference\n9)Subset\n10)exit\n")
    while (1):
        ch = int(input("\nenter your choice : "))
        if ch == 1:
            obj.insertion(s1)
            obj.display(s1)
        if ch == 2:
            obj.insertion(s2)
            obj.display(s2)
        if ch == 3:
            obj.deletion(s1)
            obj.display(s1)
        if ch == 4:
            obj.search(s1)
        if ch == 5:
            obj.size(s1)
        if ch == 6:
            u1 = []
            print("Intersection of sets : ")
            obj.intersection(u1)
            obj.display(u1)
        if ch == 7:
            print("Union of sets : ")
            u2 = s1.copy() + s2.copy()
            obj.union(u2)
            obj.display(u2)
        if ch == 8:
            u = s1.copy()
            obj.difference(u)
            obj.display(u)
        if ch == 9:
            obj.subset()
        if ch == 10:
            break

main()