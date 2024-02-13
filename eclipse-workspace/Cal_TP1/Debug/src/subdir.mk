################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Change.cpp \
../src/Factorial.cpp \
../src/Partitioning.cpp \
../src/Sum.cpp \
../src/Test.cpp 

OBJS += \
./src/Change.o \
./src/Factorial.o \
./src/Partitioning.o \
./src/Sum.o \
./src/Test.o 

CPP_DEPS += \
./src/Change.d \
./src/Factorial.d \
./src/Partitioning.d \
./src/Sum.d \
./src/Test.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"C:\Users\Eu\eclipse-workspace\Cal_TP1\cute" -I"C:\Users\Eu\eclipse-workspace\Cal_TP1\boost" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


