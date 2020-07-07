import sys
for line in sys.stdin:
    nums = line[:-1].split('.')
    if len(nums) > 1:
        zs, xs = nums[0], nums[1][:2]
    else:
        zs, xs = nums[0], '00'

    negative = False
    if zs.startswith('-'):
        negative = True
        zs = zs[1:]
    if(len(zs) == 0):
        zs = '0'
    if len(zs) > 3:
        zslist = []
        zs = zs[::-1]
        for i in range(1 + len(zs) // 3):
            zslist.append(zs[3*i:3*i+3])
        zs = ','.join(zslist)[::-1]
        if zs.startswith(','):
            zs = zs[1:]

    if len(xs) < 2:
        xs += '0'

    if negative:
        print('(${}.{})'.format(zs,xs))
    else:
        print('${}.{}'.format(zs,xs))