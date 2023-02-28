# from typing import List
# from collections import defaultdict


# class Graph:

#     def __init__(self, vertices):
#         self.V = vertices  # No. of vertices
#         self.graph = defaultdict(list)  # default dictionary to store graph

#     # function to add an edge to graph
#     def addEdge(self, u, v):
#         self.graph[u].append(v)

#     # Use BFS to check path between s and d
#     def isReachable(self, s, d):
#         # Mark all the vertices as not visited
#         visited = [False]*(self.V)

#         # Create a queue for BFS
#         queue = []

#         # Mark the source node as visited and enqueue it
#         queue.append(s)
#         visited[s] = True

#         while queue:

#             # Dequeue a vertex from queue
#             n = queue.pop(0)

#             # If this adjacent node is the destination node,
#             # then return true
#             if n == d:
#                 return True

#             # Else, continue to do BFS
#             for i in self.graph[n]:
#                 if visited[i] == False:
#                     queue.append(i)
#                     visited[i] = True
#         # If BFS is complete without visited d
#         return False

# # # Create a graph given in the above diagram
# # g = Graph(4)
# # g.addEdge(0, 1)
# # g.addEdge(0, 2)
# # g.addEdge(1, 2)
# # g.addEdge(2, 0)
# # g.addEdge(2, 3)
# # g.addEdge(3, 3)

# # u =1; v = 3

# # if g.isReachable(u, v):
# # 	print("There is a path from %d to %d" % (u,v))
# # else :
# # 	print("There is no path from %d to %d" % (u,v))

# # u = 3; v = 1
# # if g.isReachable(u, v) :
# # 	print("There is a path from %d to %d" % (u,v))
# # else :
# # 	print("There is no path from %d to %d" % (u,v))


# class Solution:
#     def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
#         g = Graph(n)
#         for i in edges:
#             g.addEdge(i[0], i[1])
#             g.addEdge(i[1], i[0])

#         return g.isReachable(source, destination)


# if __name__ == "__main__":
#     n = 3
#     edges = [[0, 1], [1, 2], [2, 0]]
#     source = 0
#     destination = 2
#     print(Solution().validPath(n, edges, source, destination))


import requests

url = "https://api.convai.com/character/getActionResponse"

payload = {'userText': 'Can you move to the spaceship?',
           'charID': 'f8e2795e-141c-11ed-995c-0242ac120003',
           'sessionID': 'ef9a4babc53cfa979036d7a47ed6a9c9',
           'voiceResponse': 'false',
           'actions': 'Moves To, Picks Up, None, Follows,  Drops',
           'classification': 'multistep',
           'objects': ' {"name": "Spaceship","description": "It\'s the spaceship Fuzzle came to Earth in!"};',
           'characters': '{"name": "Human", "bio": "The Human talking to Fuzzle."};{"name": "Fuzzle", "bio": "You know who Fuzzle is, don\'t you?"};',
           'speaker': 'Me'}
files = [

]
headers = {
    'CONVAI-API-KEY': '386ae2e9859b91e47d6597963a8e8fa3'
}

response = requests.request(
    "POST", url, headers=headers, data=payload, files=files)

print(response.text)
