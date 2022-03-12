//program untuk manajemen produk sederhana menggunakan C++
//ada beberapa fungsi yang ada didalamnya seperti:
//1. fungsi sorting yang ada pada menu:
//    - Cetak Daftar produk
//2. fungsi searching yang ada pada menu:
//    - Cari Produk
//    - Cetak Detail Order
#include <iostream>
#include <iomanip>
using namespace std;
struct produk
{
    string sku;
    char nama[30];
    long int qty;
    double harga;
};
struct order
{
    string orderNo;
    string tanggalBeli;
    string sku;
    long int qty;
    double subTotalHarga;
};
int main()
{
    int n=0;
    int nOrder=0;
    produk prod[50];
    produk tprod;
    order ordervar[50];
    order tordervar;
    int i,pil,x,pos,ki,ka,posOrder,iOrder;
    string sku,tanggal,skuBeli,orderNo,sortby;
    bool ketemu=false;
    bool ketemuOrder=false;
    menu:
    cout<<" ____________________________________________________ "<<endl;
    cout<<"|           Toko Kelompok2 XB Matrikulasi            |"<<endl;
    cout<<"|____________________________________________________|"<<endl;
    cout<<"|___________________ Menu Produk ____________________|"<<endl;
    cout<<"|    1. Tambah Produk                                |"<<endl;
    cout<<"|    2. Cetak Daftar Produk                          |"<<endl;
    cout<<"|    3. Cari Produk                                  |"<<endl;
    cout<<"|    4. Tambah Order                                 |"<<endl;
    cout<<"|    5. Cetak Detail Order                           |"<<endl;
    cout<<"|    6. Keluar                                       |"<<endl;
    cout<<"|____________________________________________________|"<<endl;
    cout<<" Pilihan Anda : "; cin>>pil;
    if(pil==1)
    {
        lagi:
        cout<<endl;
        cout<<"======================================================"<<endl;
        cout<<" Masukan Sku Produk : "; cin>>sku;
        for(i=0; i<n; i++)
        {
            if(sku == prod[i].sku)
                ketemu=true;
            else
                ketemu=false;
        }
        if(ketemu)
        {
            cout<<" Sku Produk Sudah Ada, Silahkan Masukkan Yang Lain !"<<endl;
            goto lagi;
        }
        else
        {
            cout<<"======================================================"<<endl;
            cout<<" Masukan Nama Produk      : "; cin>>prod[n].nama;
            cout<<" Masukan Jumlah Stock     : "; cin>>prod[n].qty;
            cout<<" Masukan Harga Produk     : Rp."; cin>>prod[n].harga;
        }
        n=n+1;
        prod[i].sku=sku;
        cout<<"======================================================"<<endl;
        cout<<" Kembali Ke Menu Utama (1=ya/0=tidak) : "; cin>>x;
        if (x==1){
            goto menu;
        }else{
            goto lagi;
        }
    }
    else if(pil==2)
    {
        lagiList:
        cout<<endl;
        cout<<" Urutkan Harga dan Qty Secara (asc=ascending / desc=descending : "; cin>>sortby;
        ki=0;
        while (ki<n-1)
        {
            ka=n-1;
            while(ka>ki)
            {
                if (sortby == "asc"){
                    if (prod[ka-1].harga>prod[ka].harga)	// swap all fields
                    {
                        tprod=prod[ka];
                        prod[ka]=prod[ka-1];
                        prod[ka-1]=tprod;
                    }
                    else
                    if (prod[ka-1].harga==prod[ka].harga)
                        if (prod[ka-1].qty>prod[ka].qty)	// swap all fields
                        {
                            tprod=prod[ka];
                            prod[ka]=prod[ka-1];
                            prod[ka-1]=tprod;
                        }

                    ka--;
                }else if (sortby == "desc"){
                    if (prod[ka-1].harga<prod[ka].harga)	// swap all fields
                    {
                        tprod=prod[ka];
                        prod[ka]=prod[ka-1];
                        prod[ka-1]=tprod;
                    }
                    else
                    if (prod[ka-1].harga==prod[ka].harga)
                        if (prod[ka-1].qty<prod[ka].qty)	// swap all fields
                        {
                            tprod=prod[ka];
                            prod[ka]=prod[ka-1];
                            prod[ka-1]=tprod;
                        }

                    ka--;
                }

            }
            ki++;
        }
        cout<<" ============================================================================="<<endl;
        cout<<"                             DAFTAR PRODUK                        "<<endl;
        cout<<"|====|=================|=====================|==============|=================|"<<endl;
        cout<<"| No |   Sku           |     Nama Produk     |    Harga     |   Qty           |"<<endl;
        cout<<"|====|=================|=====================|==============|=================|"<<endl;
        for(i=0; i<n; i++)
        {
            cout<<setw(4)<<i+1;;
            cout<<setw(16)<<prod[i].sku;
            cout<<setw(20)<<prod[i].nama;
            cout<<setw(16)<<prod[i].harga;
            cout<<setw(10)<<prod[i].qty<<endl;
        }
        cout<<"|====|=================|=====================|==============|=================|"<<endl;
        cout<<endl;
        cout<<" Kembali Ke Menu Utama (1=ya/0=tidak) : "; cin>>x;
        if (x==1){
            goto menu;
        }else{
            goto lagiList;
        }
    }
    else if(pil==3)
    {
        lagiCari:
        cout<<endl;
        cout<<"======================================================"<<endl;
        cout<<" Masukan SKU Yang Akan Dicari : "; cin>>sku;
        cout<<endl;
        for(i=0; i<n; i++)
        {
            if(sku==(prod[i].sku))
            {
                pos=i;
                ketemu=true;
                break;
            }
            else
                ketemu=false;
        }
        if(ketemu)
        {
            cout<<" Sku Produk               : "<<prod[pos].sku<<endl;
            cout<<" Nama Produk              : "<<prod[pos].nama<<endl;
            cout<<" Harga                    : Rp."<<prod[pos].harga<<endl;
            cout<<" Qty                      : "<<prod[pos].qty<<endl;
        }
        else
            cout<<" Produk Sku Tidak Ditemukan"<<endl<<endl;
        cout<<" Kembali Ke Menu Utama (1=ya/0=tidak) : "; cin>>x;
        if (x==1){
            goto menu;
        }else{
            goto lagiCari;
        }
    }
    else if(pil==4)
    {
        lagiorder:
        cout<<endl;
        cout<<"======================================================"<<endl;
        cout<<" Masukan Tanggal Order (dd/mm/yyyy) : "; cin>>tanggal;
        cout<<"======================================================"<<endl;
        cout<<" Masukan SKU Yang Dibeli            : "; cin>>skuBeli;
        if(skuBeli == prod[i].sku)
        {
            posOrder=i;
            ketemuOrder=true;
        }
        else
            ketemuOrder=false;

        if(ketemuOrder)
        {
            cout<<" Nama Produk                 : "<<prod[posOrder].nama<<endl;
            cout<<"======================================================"<<endl;
            cout<<" Masukan Qty Yang Dibeli     : "; cin>>ordervar[nOrder].qty;
            cout<<" Subtotal Harga              : Rp."<<(ordervar[nOrder].qty*prod[posOrder].harga)<<endl;
            prod[posOrder].qty=prod[posOrder].qty-ordervar[nOrder].qty;
        }
        else
            cout<<" Produk Sku Tidak Ditemukan"<<endl<<endl;

        nOrder=nOrder+1;
        ordervar[iOrder].orderNo= "KL2-"+to_string(nOrder);
        cout<<" No. order "<<ordervar[iOrder].orderNo<<endl;
        ordervar[iOrder].tanggalBeli=tanggal;
        ordervar[iOrder].sku=skuBeli;
        ordervar[iOrder].subTotalHarga=(ordervar[iOrder].qty*prod[posOrder].harga);
        cout<<"======================================================"<<endl;
        cout<<" Kembali Ke Menu Utama (1=ya/0=tidak) : "; cin>>x;
        if (x==1){
            goto menu;
        }else{
            goto lagiorder;
        }
    }
    else if(pil==5)
    {
        lagiCariOrder:
        cout<<endl;
        cout<<"======================================================"<<endl;
        cout<<" Masukan No.Order Yang Akan Dicetak : "; cin>>orderNo;
        cout<<endl;
        for(iOrder=0; iOrder<nOrder; i++)
        {
            if(orderNo==(ordervar[iOrder].orderNo))
            {
                posOrder=iOrder;
                ketemuOrder=true;
                break;
            }
            else
                ketemuOrder=false;
        }
        if(ketemuOrder)
        {
            cout<<" =======================================================|"<<endl;
            cout<<" Detail Order "<<orderNo<<endl;
            cout<<" Tanggal: "<<ordervar[posOrder].tanggalBeli<<endl;
            cout<<"|====|=================|==============|=================|"<<endl;
            cout<<"| No |   Sku           |    Qty       |   Total         |"<<endl;
            cout<<"|====|=================|==============|=================|"<<endl;

            cout<<setw(4)<<posOrder+1;
            cout<<setw(16)<<ordervar[posOrder].sku;
            cout<<setw(16)<<ordervar[posOrder].qty;
            cout<<setw(16)<<ordervar[posOrder].subTotalHarga;
            cout<<endl;

            cout<<"|====|=================|==============|==================|"<<endl;
            cout<<endl;
        }
        else
            cout<<" Order Tidak Ditemukan"<<endl<<endl;
        cout<<" Kembali Ke Menu Utama (1=ya/0=tidak) : "; cin>>x;
        if (x==1){
            goto menu;
        }else{
            goto lagiCariOrder;
        }
    }
    else
    {
        cout<<endl<<" Terima Kasih ......"<<endl<<endl;
    }
    return 0;
}