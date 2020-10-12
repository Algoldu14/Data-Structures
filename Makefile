.PHONY: clean All

All:
	@echo "----------Building project:[ EEDD - Debug ]----------"
	@"$(MAKE)" -f  "EEDD.mk"
clean:
	@echo "----------Cleaning project:[ EEDD - Debug ]----------"
	@"$(MAKE)" -f  "EEDD.mk" clean
