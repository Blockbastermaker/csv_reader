Import('env')

Files = Glob("src/*.cc") + Glob("src/**/*.cc") + ["test/test.cc"]

csv_test = env.Program(target="csv_test", source=Files)

env.Default(csv_test)
