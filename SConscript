Import('env')
localEnv = env.Clone()

sources = [
'Sources/ListenableSampledInput.cpp',
'Sources/InvertedListenableSampledInput.cpp',
]

library = localEnv.Library('OO-IO', sources )
localEnv.Append(LIBS=library)

utils = env.SConscript('utils/SConscript' )
localEnv.Append(LIBS=utils)

testList =  [
'UnitTest/ListenableSampledInput.t.h',
'UnitTest/InvertedListenableSampledInput.t.h',
]

localEnv.CxxTest('testrunner',testList, CXXFLAGS='-Wall -W -Wextra')

Return('library')