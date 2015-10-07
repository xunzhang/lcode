class Solution(object):

    def compareVersion(self, version1, version2):
        """
        :type version1: str
        :type version2: str
        :rtype: int
        """
        def lcmp(lst1, lst2):
            v1 = int(lst1[0]) if lst1 else 0
            v2 = int(lst2[0]) if lst2 else 0
            if v1 > v2:
                print 'ss'
                return 1
            elif v1 < v2:
                return -1
            else:
                print lst1, lst2
                if not lst1[1:] and not lst2[1:]:
                    return 0
                return lcmp(lst1[1:], lst2[1:])
        return lcmp(version1.split('.'), version2.split('.'))

if __name__ == '__main__':
    a = Solution()
    print a.compareVersion('1', '0')
