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
        'conf.h' 'fbpad-256.info' 'LICENSE')
noextract=()
md5sums=('SKIP'
         '4ee1d0c9058a15a449a6bba9e5b9c78c'
         '185b9d6ec1c539213226a3e2509c7ccd'
         'ec67f29a7dec10f86ef31515ed657a91')
sha1sums=('SKIP'
          '283da1a6ab9531cc60e36bf2f0d961c8122ea434'
          'dbb816fe37faf0acb4e1a916d7493787c2b647fc'
          '76a535243054e1fdd9caaa46a1571cd381d74353')
sha256sums=('SKIP'
            '5103c4f88566b9632199c0c4251f777f78934afae915781793d8334633d35589'
            'fb8ae049aa7d41fb285cbf7aa4487b28014273ebcfceefb4d58fb07018312e9c'
            '0ea8d51c57a3a59ca57428b6fe9b47fdb1fde281fc1b095c9832872e85b09a72')

pkgver() {
  cd $srcdir/$pkgname
  printf "r%s.%s" "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

prepare() {
  cd $srcdir/$pkgname
  ## Custom config.h
  cp $srcdir/conf.h conf.h
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

