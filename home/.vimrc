" Basic stuff
set nocompatible         " no vi compatibility

let g:ctags_path = "/usr/local/bin/ctags"

if filereadable(glob("~/.vimrc.plugins")) 
  source ~/.vimrc.plugins
endif

set number               " line numbers
set fileformat=unix      " LF line endings

" Turn on auto indentation
filetype indent on
filetype plugin on

" Use 2 spaces softtabs for everything except for languages where the
" convention is 4spaces softtabs
autocmd FileType * set ts=2 sw=2 sts=2 expandtab
autocmd FileType c,m,h,cpp,hpp,glsl,objc,python,php,swift,rust set ts=4 sw=4 sts=4 expandtab
autocmd FileType make set noexpandtab " make needs them tabs

" Serious indentation for XML
autocmd FileType xml setlocal equalprg=xmllint\ --format\ --recover\ -\ 2>/dev/null
autocmd FileType json setlocal equalprg=jsonlint\ -\ 2>/dev/null

" Comment out Jekyll / Middelman frontmatter for files that commonly have it
function CommentFrontMatter()
  syntax match Comment /\%^---\_.\{-}---$/ contains=@Spell
endfunction

autocmd BufNewFile,BufRead *.rst,*.md,*.markdown call CommentFrontMatter()
autocmd BufNewFile,BufRead *.deface set filetype=eruby.html
autocmd BufNewFile,BufRead *.mrb set filetype=ruby
autocmd BufNewFile,BufRead *.js.erb set filetype=javascript
autocmd BufNewFile,BufRead *.boot set filetype=clojure

function! WordMode()
  setlocal formatoptions=t1
  setlocal textwidth=80
  map j gj
  map k gk
  setlocal smartindent
  setlocal spell spelllang=en_us
endfunction
command! WordMode call WordMode()

" Colorscheme
syntax on
set t_Co=256

set listchars=tab:▸·,eol:¬,trail:·

" The following assume t_Co == 256 for term colors
 "For a color table check http://en.wikipedia.org/wiki/Xterm
highlight NonText ctermfg=236 guifg=#303030
highlight SpecialKey ctermfg=236 guifg=#303030
highlight ColorColumn ctermbg=0
highlight CursorLine term=none gui=none

set cursorline           " Highlight current line
set list                 " Activate listchars configuration
set ruler                " Show row / column
set showcmd              " Shows selection
set incsearch            " Use incremental search
set hlsearch             " Highlight search results

" Natural splits
set splitbelow
set splitright

let s:fontsize = 22

let &guifont = escape("Hack" . ":h" . s:fontsize, ' ')

set virtualedit=all      " Allow to move cursor anywhere
set clipboard=unnamed    " Uses system clipboard
let mapleader = ','

" Folding options
set foldmethod=syntax
set nofoldenable         " Don't fold by default

map <Leader>d <C-]>
map à <C-]>

" Allow backgrounding buffers without writing them, and remember marks/undo
" for backgrounded buffers
set hidden

" Make searches case-sensitive only if they contain upper-case characters
set ignorecase
set smartcase

set winwidth=83          " 79(+4 for line numbers)
set cmdheight=2          " Command buffer height = 2

set title                " Change the terminal's title
set visualbell           " Don't beep
set noerrorbells         " Don't beep

set nobackup             " I use git anyway
set noswapfile           " See previous line

set pastetoggle=<F2>     " Allows to enter 'paste mode'

set modeline
set modelines=2

" Prevent Vim from clobbering the scrollback buffer. See
" http://www.shallowsky.com/linux/noaltscreen.html
set t_ti= t_te=
" keep more context when scrolling off the end of a buffer
set scrolloff=3

" Ignore these files when using CtrlP
" * Rails specific
set wildignore+=*/tmp/*,*/.sass_cache/*,*/vendor/assets/*,*/public/assets/*
" * Python specific
set wildignore+=*.pyc*
" * C specific
set wildignore+=*/build/*,*.d,*.o
" * SCM specific
set wildignore+=*/.git/*,*/.hg/*,*/.svn/*
" * JavaScript specific
set wildignore+=*/dist/*,*/bower_components/*,*/node_modules/*,*/jspm_packages/*

" Really useful to save a file with sudo
cmap w!! w !sudo tee % >/dev/null

" Clears the search buffer when hitting return
nnoremap <CR> :nohlsearch<cr>

" Better indentation
vnoremap < <gv
vnoremap > >gv

" disable Ex mode
nnoremap Q <Nop>
imap <Home> <Esc>
vnoremap <Home> <Esc>

 " Move through windows

  noremap <f1> :bprev<CR> 
  noremap <f2> :bnext<CR>

nnoremap <PageUp> <C-u>
nnoremap <PageDown> <C-d>
