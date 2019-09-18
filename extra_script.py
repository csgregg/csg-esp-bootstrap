import os
import gzip
import shutil

Import("env")

platform = env.PioPlatform()


def deflate_www(sourceFolder,destFolder):
    print('Deflating www files -')
    for folder, subfolders, files in os.walk(sourceFolder):
        for file in files:
            print(os.path.join(folder, file))
            with open(os.path.join(folder, file), 'rb') as f_in:
                with gzip.open(os.path.join(destFolder, file) + '.gz', 'wb') as f_out:
                    shutil.copyfileobj(f_in, f_out)
    print('Deflating complete')


env.AddPreAction("$BUILD_DIR/partitions.bin", deflate_www(".\www",".\data"))