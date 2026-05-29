import subprocess

p = subprocess.Popen(
    "dir",
    shell = True,
    stdout = subprocess.PIPE,
    text = True
)

out = p.stdout.read()
print(out)

print(p.returncode)