"
" vim bindings for competitive programming
"

" change all
map <leader>ca ggcG

function Template()
	silent execute "! cp " . "x/template." . expand('%:e') . " " . @%
	edit
	redraw!

	execute "normal! gg"
	" 0r checklist.txt
endfunction
command! Template call Template()

" ./run 1
autocmd filetype cpp  command! -nargs=+ Run execute "!./run " . <args>

if has('nvim')
	autocmd filetype cpp  command! Out split term://./out
else
	autocmd filetype cpp  command! Out execute "!./out"
endif

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


