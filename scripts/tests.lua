local inputfile = 'inp'
local executable = 'out'
local separator = '---'

local function read_testcases()
    local res = {}
    local buf = {}
    for line in io.lines(inputfile) do
        if line:find("^" .. separator) ~= nil then
            -- Add testcase
            if buf ~= nil then
                res[#res + 1] = table.concat(buf, "\n")
                buf = {}
            end
        else
            -- Append line to the buffer
            buf[#buf + 1] = line
        end
    end

    -- Add last testcase
    if buf ~= nil then
        res[#res + 1] = table.concat(buf, "\n")
    end

    return res
end

local function run(input)
    local inp = io.open('.testcase.in', 'w')
    inp:write(input)
    inp:close()

    os.execute('./' .. executable .. ' < .testcase.in > .testcase.out')

    local out = io.open('.testcase.out', 'r')
    local res = out:read('*a')
    out:close()
    return res
end

function main()
    local tests = read_testcases()
    for i = 1, #tests do
        if i > 1 then
            print("--------------------------------------------------------------------------------")
        end
        local input = tests[i]
        local output = run(input)
        io.write(output)
    end
end

main()

