objects := list.o  

main: $(objects)
	gcc ./build/$^ -o $@

$(objects): %.o: ./src/%.c
	mkdir -p ./build/
	gcc -c $^ -o ./build/$@

clean:
	rm -fr ./build/ main



