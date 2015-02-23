import sys

PREFIX = u'//*'

sys.stdout = open("README.md", "w", encoding="utf-8")

code = False
with open("helloworld.c", "r", encoding="utf-8-sig") as f:
    for line in f:
        if '//-->' in line:
            print('``` cpp')
            code = True
            continue
        if '//<--' in line:
            print('```')
            code = False
            continue
        if code:
            print(line.rstrip())
            continue
        if line.startswith(PREFIX):
            print(line[len(PREFIX):].strip())



