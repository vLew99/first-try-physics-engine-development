let location = "~/.builds/CollisionSystem"
nnoremap <F5> :execute '!trash-put ' location<CR>
nnoremap <F6> :execute '!cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B' location<CR>
nnoremap <F7> :execute '!cmake --build' location<CR>
nnoremap <F8> :execute '!ln -s' location 'build'<CR>
