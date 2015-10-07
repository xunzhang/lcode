class Solution(object):

    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        D = {}
        S = {}
        words = str.split()
        if len(pattern) != len(words): return False
        for i in xrange(len(pattern)):
        if D.get(pattern[i]):
            if D[pattern[i]] != words[i]: return False
            elif S.get(words[i]): return False
            D[pattern[i]] = words[i]
            S[words[i]] = 1
        return True
