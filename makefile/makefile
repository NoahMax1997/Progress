cc = g++
target=server
deps=$(shell find ./ -name "*.h")
src=$(shell find ./ -name "*.cpp")
obj=${src:%.cpp=%.o}
${target}:${obj}
	${cc} -o ${target} ${obj} -lpthread -g
${%.o}:${%.c} ${deps}
	${cc} -c $< -o $@
clean:
	rm -rf ${obj} ${target}
