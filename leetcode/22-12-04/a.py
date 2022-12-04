
class Solution:
    def isCircularSentence(self, sentence: str) -> bool:
        li = sentence.split(" ")
        n = len(li)
        for i in range(n):
            if i + 1 < n and li[i][-1] != li[i + 1][0]:
                return False
        return li[-1][-1] == li[0][0]