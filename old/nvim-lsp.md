install: bear, ccls

Or use https://github.com/nickdiego/compiledb instead of bear?

```lua

local Plug = vim.fn['plug#']
vim.call('plug#begin')
Plug 'https://github.com/nvim-treesitter/nvim-treesitter'
Plug 'https://github.com/neovim/nvim-lspconfig'
vim.call('plug#end')

require'lspconfig'.ccls.setup{}

require'nvim-treesitter.configs'.setup {
        ensure_installed = { "c", "lua", "vim", "vimdoc", "markdown", "hare", "python", "diff", "git_rebase" },
        sync_install = false,
        auto_install = true,
        ignore_install = { "javascript" },
        highlight = {
                enable = true,
                -- disable = { "c", "rust" },
                disable = function(lang, buf)
                        local max_filesize = 100 * 1024 -- 100 KB
                        local ok, stats = pcall(vim.loop.fs_stat, vim.api.nvim_buf_get_name(buf))
                        if ok and stats and stats.size > max_filesize then
                                return true
                        end
                end,
                additional_vim_regex_highlighting = false,
        },
}
```
