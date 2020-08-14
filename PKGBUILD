# Contributor: Sara <sara at archlinux dot us>
# Maintainer: aksr <aksr at t-com dot me>
pkgname=fbpad-git
pkgver=r273.52b6bed
pkgrel=1
pkgdesc="A small linux framebuffer virtual terminal."
arch=('i686' 'x86_64')
url="http://repo.or.cz/w/fbpad.git"
license=('ISC')
groups=()
depends=()
makedepends=('git' 'ft2tf' 'ttf-dejavu')
optdepends=()
provides=('fbpad')
conflicts=('fbpad')
replaces=()
backup=()
options=()
install=${pkgname}.install
source=("$pkgname::git://repo.or.cz/fbpad.git"
        'conf.h' 'fbpad-256.info' 'LICENSE' 'shortcuts.patch')
noextract=()
md5sums=('SKIP'
         '6213359f0a9ccc28172c6a97e8359a0c'
         '185b9d6ec1c539213226a3e2509c7ccd'
         'ec67f29a7dec10f86ef31515ed657a91'
         '7cb5fd2c0cc2d3b8bdbd4d037fe315fe')
sha1sums=('SKIP'
          'bf9333f1faf9a93a6112761fd77e49adef5c5693'
          'dbb816fe37faf0acb4e1a916d7493787c2b647fc'
          '76a535243054e1fdd9caaa46a1571cd381d74353'
          '61dc7612f0473357b548a27c5bd2dc07d9d28576')
sha256sums=('SKIP'
            '4ce1e3f1a1305628d7511ac43971455e5be5d1278928787ab811b965fe582a60'
            'fb8ae049aa7d41fb285cbf7aa4487b28014273ebcfceefb4d58fb07018312e9c'
            '0ea8d51c57a3a59ca57428b6fe9b47fdb1fde281fc1b095c9832872e85b09a72'
            '1b0aad56c0d232666a8e57afdc1314bbe8b6cb293e79fc28d40057c561d77b3d')

pkgver() {
  cd $srcdir/$pkgname
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

prepare() {
  cd $srcdir/$pkgname
  ## Custom config.h
  cp $srcdir/conf.h conf.h

  ## Add shortcuts
  patch <"$srcdir/shortcuts.patch"
}

build() {
  cd $srcdir/$pkgname
  make
}

package() {
  cd $srcdir/$pkgname
  install -Dm755 ../$pkgname/fbpad $pkgdir/usr/bin/fbpad
  install -Dm644 ../$pkgname/README $pkgdir/usr/share/doc/${pkgname%-*}/README
  install -Dm644 ../LICENSE $pkgdir/usr/share/licenses/${pkgname%-*}/LICENSE
  ## Compile terminfo
  mkdir -p $pkgdir/usr/share/terminfo
  tic -x -o $pkgdir/usr/share/terminfo $srcdir/fbpad-256.info

  ## Setup fonts
  if [ -x /usr/bin/fbpad-mkfn ]; then FT2TF="fbpad-mkfn -h18 -w9"; SZ="8h125v125b0a1"; else FT2TF=ft2tf; SZ=5; fi
  $FT2TF /usr/share/fonts/nerd-fonts-complete/TTF/Hack\ Regular\ Nerd\ Font\ Complete.ttf:$SZ > $srcdir/font-r.tf
  $FT2TF /usr/share/fonts/nerd-fonts-complete/TTF/Hack\ Italic\ Nerd\ Font\ Complete.ttf:$SZ  > $srcdir/font-i.tf
  $FT2TF /usr/share/fonts/nerd-fonts-complete/TTF/Hack\ Bold\ Nerd\ Font\ Complete.ttf:$SZ    > $srcdir/font-b.tf

  ## Install fonts
  install -Dm644 ../font-r.tf $pkgdir/usr/share/${pkgname%-*}/font-r.tf
  install -Dm644 ../font-i.tf $pkgdir/usr/share/${pkgname%-*}/font-i.tf
  install -Dm644 ../font-b.tf $pkgdir/usr/share/${pkgname%-*}/font-b.tf
}

