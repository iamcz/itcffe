src = $(wildcard *.cpp) $(wildcard */*.cpp) $(wildcard utilities/*/*.cpp)
obj = $(src:.cpp=.o)

EuropeanOptionTest : $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

print-% : ; @echo $* = $($*)

.PHONY: clean
clean:
	rm -f $(obj) myprog
