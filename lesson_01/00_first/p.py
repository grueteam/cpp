with open("helloworld.c") as f:
    for line in f:
        if '//-->' in line:
          print('``` cpp')
        print(line)
        if '//<--' in line:
          print('```')

