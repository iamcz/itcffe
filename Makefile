src = $(wildcard utilities/*/*.cpp) $(wildcard */*.cpp)
obj = $(src:.cpp=.o)

EuropeanOptionTest : $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

print-% : ; @echo $* = $($*)

.PHONY: clean
clean:
	rm -f $(obj) myprog
