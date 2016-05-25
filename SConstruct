import os

env = Environment()
sources = env.Glob("src/*.cc")
boost_prefix = "/usr/local"
env.Append(CPPPATH = [os.path.join(boost_prefix, "include"), "include"])
env.Append(CCFLAGS = ['-std=c++1y', '-Wall', '-g'])
env.Append(LIBPATH = [os.path.join(boost_prefix, "lib")])
app = env.Program(target = "bin/app", source = sources, LIBS = ['boost_system-mt', 'boost_regex-mt'])

env.Default(app)

