--
-- neovim bindings for competitive programming
--

if vim.g.loaded_comprog == 1 then return end
vim.g.loaded_comprog = 1

if not vim.fn.getcwd():match('/comprog') then return end

local function write(filename, content)
    local file = io.open(filename, "w")
    file:write(content)
    file:close()
end

local function input(param)
    local requests = require 'requests'

    print("Getting testcases for <" .. param.args .. ">...")

    local response = requests.get(param.args)
    local body = response.text
    if response.status_code ~= 200 then
        write('inp', body)
        return
    end

    local regex = '<pre id="id%d+">(.*?)</pre>'
    local testcases = {  }
    for match in body:gmatch(regex) do
        testcases[#testcases+1] = match
    end

    write('inp', table.concat(testcases, '\n-----------------------------------\n'))
    write('del.html', body)
    print("Done!")
end

vim.api.nvim_create_user_command('Input', input, { nargs=1 })

-- old .exrc
vim.cmd([[
    " change all
    map <leader>ca gg"_cG

    function Template()
        " silent execute '! cp ' . 'x/template.' . expand('%:e') . ' ' . @%
        normal! ggdG
        silent execute "0r x/template." . expand('%:e')
        " edit
        redraw!

        execute "normal! gg"
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

