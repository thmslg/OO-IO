Import('env')

sources = [
'Sources/ListenerSubject.cpp',
'Sources/ListenableSampledInput.cpp',
'Sources/InvertedListenableSampledInput.cpp',
] 
library = env.Library('OO-IO', sources )

testList =  [
'UnitTest/DelegateBooleanParameter.t.h',
'UnitTest/ObserverSubject.t.h',
'UnitTest/ListenableSampledInput.t.h',
'UnitTest/InvertedListenableSampledInput.t.h',
]

env.Append(LIBS=library)
env.CxxTest('testrunner',testList, CXXFLAGS='-Wall -W -Wextra')

Return('library')