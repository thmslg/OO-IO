Import('env')

sources = [
'Sources/ListenableSampledInput.cpp',
'Sources/InvertedListenableSampledInput.cpp',
] 

utils = SConscript('utils/SConscript')

library = env.Library('OO-IO', sources + utils )

testList =  [
'UnitTest/ListenableSampledInput.t.h',
'UnitTest/InvertedListenableSampledInput.t.h',
]

env.Append(LIBS=library)
env.CxxTest('testrunner',testList, CXXFLAGS='-Wall -W -Wextra')

Return('library')