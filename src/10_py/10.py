class Graph:

    def __init__(self):
        self.graph = {}

    def add_point(self, a, b):

        if a not in self.graph:
            self.graph[a] = []
        if b not in self.graph:
            self.graph[b] = []

        self.graph[a].append(b)
        self.graph[b].append(a)

    def dfs(self, start):

        if start not in self.graph:
            return []

        stack = [start]
        visit = []

        while stack:
            point = stack.pop()
            if point not in visit:
                visit.append(point)
                for i in (reversed(self.graph[point])): #суть здесь в том, что я, ,например, добавил B, C, затем иду в C, хотя хотелось бы в B
                    stack.append(i)                     #поэтому я добавляю в обратонм порядке, т.е потом я возбму сверху B, а не C
        return visit

    def __iter__(self):

        if self.graph:
            self.result = self.dfs(list(self.graph.keys())[0])

        else:
            self.result = []

        self.index = 0

        return self

    def __next__(self):
        if self.index < len(self.result):
            r = self.result[self.index]
            self.index += 1
            return r
        raise StopIteration

g = Graph()

# Граф в виде схемы:
#   A
#  / \
# B   C
# |   |
# D   E
#  \ /
#   F

g = Graph()
g.add_point('A', 'B')
g.add_point('A', 'C')
g.add_point('B', 'D')
g.add_point('C', 'E')
g.add_point('D', 'F')
g.add_point('E', 'F')

for j in g:
    print(j)
