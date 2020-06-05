require 'open3'

total = ARGV[0]
x = 0
list = []

while (list.length < total.to_i) do
    y = rand(1..(total.to_i) + 1)
    if !(list.include? y.to_s)
        list.push(y.to_s)
    end
end
ret = String.new
list.each do |item|
    ret += "#{item} "
end

if ARGV[1] <=> "DEBUG"
    puts "Start Debug Run"
    Open3.popen2e("./push_swap #{ret}") do |_in, stdout_stderr, _pid|
        Thread.new do
            stdout_stderr.each {|l| puts l }
        end
        _in.close
        _pid.value
    end
else
puts "Start Valgrind"
Open3.popen2e("./push_swap #{ret} | wc -l") do |_in, stdout_stderr, _pid|
    Thread.new do
        stdout_stderr.each {|l| puts l }
    end
    _in.close
    _pid.value
end
puts
puts

puts "Negative test?? KO expected"

cmd = "./checker 0 9 1 8 2 7 3 6 4 5"
Open3.popen2e(cmd) do |_in, stdout_stderr, _pid|
    Thread.new do
        stdout_stderr.each { |l| puts l }
    end
    _in.puts "sa"
    _in.puts "pb"
    _in.puts "rr"
    _in.close
    _pid.value
end

puts "OK Expected"
cmd = "./checker 0 9 1 8 2"
Open3.popen2e(cmd) do |_in, stdout_stderr, _pid|
    Thread.new do
        stdout_stderr.each { |l| puts l }
    end
    _in.puts "pb"
    _in.puts "ra"
    _in.puts "pb"
    _in.puts "ra"
    _in.puts "sa"
    _in.puts "ra"
    _in.puts "pa"
    _in.puts "pa"
    _in.close
    _pid.value
end

puts "=====Should be empty"
Open3.popen2e("./push_swap") do |_in, stdout_stderr, _pid|
    Thread.new do
        stdout_stderr.each { |l| puts l }
    end
    _in.close
    _pid.value
end
puts "=====End"

puts "=====Should be empty"
Open3.popen2e("./push_swap 0 1 2 3 4 5 6 7 8 9") do |_in, stdout_stderr, _pid|
    Thread.new do
        stdout_stderr.each { |l| puts l }
    end
    _in.close
    _pid.value
end
puts "=====End"

puts "Start testing"
Open3.popen2e("valgrind ./push_swap #{ret} | valgrind ./checker #{ret}") do |_in, stdout_stderr, _pid|
    Thread.new do
        stdout_stderr.each { |l| puts l }
    end
    _in.close
    _pid.value
end
end
