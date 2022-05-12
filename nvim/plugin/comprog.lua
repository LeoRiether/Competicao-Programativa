--
-- neovim bindings for competitive programming
--

if vim.g.loaded_comprog == 1 then return end
vim.g.loaded_comprog = 1

if not vim.fn.getcwd():match('/comprog') then return end

-- Keymaps
local map = vim.api.nvim_set_keymap
local function lmap(lhs, rhs) -- leader map
    map('n', '<leader>'..lhs, rhs, {noremap=true})
end

lmap('comp', ':Comp<cr>')
lmap('test', ':Test<cr>')
lmap('run', ':Run<cr>')
lmap('lib', ':Lib<cr>')
lmap('tem', ':Template<cr>')

-- :Input
local function write(filename, content)
    local file = io.open(filename, "w")
    file:write(content)
    file:close()
end

local function input(problem)
    -- ensure we have a buffer called `inp` in the first place
    if vim.fn.bufnr("inp") == -1 then
        vim.api.nvim_err_writeln("comprog: inp buffer not found")
        return
    end

    -- Format `inp`
    local cases = {}
    for _, test in pairs(problem.tests) do
        cases[#cases+1] = test.input
    end
    cases = table.concat(cases, string.rep('-' , 35) .. '\n')
    local pad0 = (35 - #problem.name - 2 + 1) / 2
    local pad1 = (35 - #problem.name - 2) / 2
    if pad0 < 3 then pad0 = 3 end
    local text = string.format('%s %s %s\n%s', string.rep('-', pad0), problem.name, string.rep('-', pad1), cases)
    write('inp', text)

    -- reload the `inp` buffer, then go back to the original one
    local cur_buf = vim.fn.bufnr("%")
    vim.cmd('b inp | e | b ' .. cur_buf)

    vim.api.nvim_out_write("Updated test cases\n")
end

-- :h tcp
local function create_server(host, port, on_connect)
    local server = vim.loop.new_tcp()
    server:bind(host, port)
    server:listen(128, function(err)
        assert(not err, err)  -- Check for errors.
        local sock = vim.loop.new_tcp()
        server:accept(sock)  -- Accept client connection.
        on_connect(sock)  -- Start reading messages.
    end)
    return server
end

local function start_competitive_companion_server()
    create_server('127.0.0.1', 10043, function(sock)
        local buffer = {}
        sock:read_start(function(err, chunk)
            assert(not err, err)  -- Check for errors.
            if chunk then
                buffer[#buffer+1] = chunk
            else  -- EOF (stream closed).
                local body = table.concat(buffer, "")
                local idx = body:match("^.*()\r\n") -- copied from p00f/cphelper.nvim
                if idx == nil then return end -- ensure the message is in the right format
                body = body:sub(idx + 1)
                vim.schedule(function()
                    input(vim.json.decode(body))
                end)

                sock:close() -- Always close handles to avoid leaks.
                buffer = {}
            end
        end)
    end)
end

start_competitive_companion_server()
vim.api.nvim_create_user_command('Input', input, { nargs=1 })

-- :Lib
local function lib_copy()
    vim.fn['fzf#run'](vim.fn['fzf#wrap'](vim.fn['fzf#vim#with_preview']({
        source = 'rg lib/ --files',
        sink = 'read',
        options = { '--prompt', 'Lib> ', },
    })))
end

vim.api.nvim_create_user_command('Lib', lib_copy, {})

-- old .exrc
vim.cmd([[
    function Template()
        normal! ggdG
        silent execute "0r x/template." . expand('%:e')
        redraw!
        normal! gg
        " 0r checklist.txt
    endfunction
    command! Template call Template()

    autocmd filetype cpp  command! Comp execute "!./comp " . @%

    command! Test execute "!./test"
    nnoremap - 35a-<esc>

    autocmd filetype cpp  command! Out split term://./out

    " ./run 1
    " autocmd filetype cpp  command! -nargs=+ Run execute "!./run " . <args>
    function Run()
        Comp
        Test
    endfunction
    autocmd filetype cpp  command! Run call Run()

    " Debug template
    iabbr __debug 
                \#ifdef DEBUG
                \<cr>#define debug(...) __VA_ARGS__
                \<cr>#define judge(...)
                \<cr>#else
                \<cr>#define endl '\n'
                \<cr>#define debug(...)
                \<cr>#define judge(...) __VA_ARGS__
                \<cr>#endif
                \<cr>#define debugf(...) debug(printf(__VA_ARGS__))
]])

