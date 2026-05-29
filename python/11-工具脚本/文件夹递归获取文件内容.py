import os

def get_all_files(path):


    items = list(os.scandir(path))

    items.sort(key=lambda x:(not x.is_dir(), x.name))

    for item in items:


        if item.is_dir():

            get_all_files(item.path)

        else:
            all_files.append(item.path.strip('\\').split('\\')[-1])


    return all_files

all_files = []
path = r"C:\Users\zigyr\Desktop\zigyr.github.io\_posts"
all_files = get_all_files(path)

print(all_files)
