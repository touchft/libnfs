/*
 * Please do not edit this file.
 * It was generated using rpcgen.
 */

#ifndef _NFS_H_RPCGEN
#define _NFS_H_RPCGEN




#ifdef __cplusplus
extern "C" {
#endif

#define NFS3_FHSIZE 64
#define NFS3_WRITEVERFSIZE 8
#define NFS3_CREATEVERFSIZE 8
#define NFS3_COOKIEVERFSIZE 8

#if defined(ANDROID)
typedef long long int quad_t;
typedef long long unsigned u_quad_t;
#endif

typedef char cookieverf3[NFS3_COOKIEVERFSIZE];

typedef u_quad_t uint64;

typedef uint64 cookie3;

struct nfs_fh3 {
	struct {
		u_int data_len;
		char *data_val;
	} data;
};
typedef struct nfs_fh3 nfs_fh3;

typedef char *filename3;

struct diropargs3 {
	nfs_fh3 dir;
	filename3 name;
};
typedef struct diropargs3 diropargs3;

enum ftype3 {
	NF3REG = 1,
	NF3DIR = 2,
	NF3BLK = 3,
	NF3CHR = 4,
	NF3LNK = 5,
	NF3SOCK = 6,
	NF3FIFO = 7,
};
typedef enum ftype3 ftype3;

typedef u_int mode3;

typedef u_int uid3;

typedef u_int gid3;

typedef uint64 size3;

typedef uint64 fileid3;

struct specdata3 {
	u_int specdata1;
	u_int specdata2;
};
typedef struct specdata3 specdata3;

struct nfstime3 {
	u_int seconds;
	u_int nseconds;
};
typedef struct nfstime3 nfstime3;

struct fattr3 {
	ftype3 type;
	mode3 mode;
	u_int nlink;
	uid3 uid;
	gid3 gid;
	size3 size;
	size3 used;
	specdata3 rdev;
	uint64 fsid;
	fileid3 fileid;
	nfstime3 atime;
	nfstime3 mtime;
	nfstime3 ctime;
};
typedef struct fattr3 fattr3;

struct post_op_attr {
	bool_t attributes_follow;
	union {
		fattr3 attributes;
	} post_op_attr_u;
};
typedef struct post_op_attr post_op_attr;

enum nfsstat3 {
	NFS3_OK = 0,
	NFS3ERR_PERM = 1,
	NFS3ERR_NOENT = 2,
	NFS3ERR_IO = 5,
	NFS3ERR_NXIO = 6,
	NFS3ERR_ACCES = 13,
	NFS3ERR_EXIST = 17,
	NFS3ERR_XDEV = 18,
	NFS3ERR_NODEV = 19,
	NFS3ERR_NOTDIR = 20,
	NFS3ERR_ISDIR = 21,
	NFS3ERR_INVAL = 22,
	NFS3ERR_FBIG = 27,
	NFS3ERR_NOSPC = 28,
	NFS3ERR_ROFS = 30,
	NFS3ERR_MLINK = 31,
	NFS3ERR_NAMETOOLONG = 63,
	NFS3ERR_NOTEMPTY = 66,
	NFS3ERR_DQUOT = 69,
	NFS3ERR_STALE = 70,
	NFS3ERR_REMOTE = 71,
	NFS3ERR_BADHANDLE = 10001,
	NFS3ERR_NOT_SYNC = 10002,
	NFS3ERR_BAD_COOKIE = 10003,
	NFS3ERR_NOTSUPP = 10004,
	NFS3ERR_TOOSMALL = 10005,
	NFS3ERR_SERVERFAULT = 10006,
	NFS3ERR_BADTYPE = 10007,
	NFS3ERR_JUKEBOX = 10008,
};
typedef enum nfsstat3 nfsstat3;

enum stable_how {
	UNSTABLE = 0,
	DATA_SYNC = 1,
	FILE_SYNC = 2,
};
typedef enum stable_how stable_how;

typedef uint64 offset3;

typedef u_int count3;

struct wcc_attr {
	size3 size;
	nfstime3 mtime;
	nfstime3 ctime;
};
typedef struct wcc_attr wcc_attr;

struct pre_op_attr {
	bool_t attributes_follow;
	union {
		wcc_attr attributes;
	} pre_op_attr_u;
};
typedef struct pre_op_attr pre_op_attr;

struct wcc_data {
	pre_op_attr before;
	post_op_attr after;
};
typedef struct wcc_data wcc_data;

struct WRITE3args {
	nfs_fh3 file;
	offset3 offset;
	count3 count;
	stable_how stable;
	struct {
		u_int data_len;
		char *data_val;
	} data;
};
typedef struct WRITE3args WRITE3args;

typedef char writeverf3[NFS3_WRITEVERFSIZE];

struct WRITE3resok {
	wcc_data file_wcc;
	count3 count;
	stable_how committed;
	writeverf3 verf;
};
typedef struct WRITE3resok WRITE3resok;

struct WRITE3resfail {
	wcc_data file_wcc;
};
typedef struct WRITE3resfail WRITE3resfail;

struct WRITE3res {
	nfsstat3 status;
	union {
		WRITE3resok resok;
		WRITE3resfail resfail;
	} WRITE3res_u;
};
typedef struct WRITE3res WRITE3res;

struct LOOKUP3args {
	diropargs3 what;
};
typedef struct LOOKUP3args LOOKUP3args;

struct LOOKUP3resok {
	nfs_fh3 object;
	post_op_attr obj_attributes;
	post_op_attr dir_attributes;
};
typedef struct LOOKUP3resok LOOKUP3resok;

struct LOOKUP3resfail {
	post_op_attr dir_attributes;
};
typedef struct LOOKUP3resfail LOOKUP3resfail;

struct LOOKUP3res {
	nfsstat3 status;
	union {
		LOOKUP3resok resok;
		LOOKUP3resfail resfail;
	} LOOKUP3res_u;
};
typedef struct LOOKUP3res LOOKUP3res;

struct COMMIT3args {
	nfs_fh3 file;
	offset3 offset;
	count3 count;
};
typedef struct COMMIT3args COMMIT3args;

struct COMMIT3resok {
	wcc_data file_wcc;
	writeverf3 verf;
};
typedef struct COMMIT3resok COMMIT3resok;

struct COMMIT3resfail {
	wcc_data file_wcc;
};
typedef struct COMMIT3resfail COMMIT3resfail;

struct COMMIT3res {
	nfsstat3 status;
	union {
		COMMIT3resok resok;
		COMMIT3resfail resfail;
	} COMMIT3res_u;
};
typedef struct COMMIT3res COMMIT3res;
#define ACCESS3_READ 0x0001
#define ACCESS3_LOOKUP 0x0002
#define ACCESS3_MODIFY 0x0004
#define ACCESS3_EXTEND 0x0008
#define ACCESS3_DELETE 0x0010
#define ACCESS3_EXECUTE 0x0020

struct ACCESS3args {
	nfs_fh3 object;
	u_int access;
};
typedef struct ACCESS3args ACCESS3args;

struct ACCESS3resok {
	post_op_attr obj_attributes;
	u_int access;
};
typedef struct ACCESS3resok ACCESS3resok;

struct ACCESS3resfail {
	post_op_attr obj_attributes;
};
typedef struct ACCESS3resfail ACCESS3resfail;

struct ACCESS3res {
	nfsstat3 status;
	union {
		ACCESS3resok resok;
		ACCESS3resfail resfail;
	} ACCESS3res_u;
};
typedef struct ACCESS3res ACCESS3res;

struct GETATTR3args {
	nfs_fh3 object;
};
typedef struct GETATTR3args GETATTR3args;

struct GETATTR3resok {
	fattr3 obj_attributes;
};
typedef struct GETATTR3resok GETATTR3resok;

struct GETATTR3res {
	nfsstat3 status;
	union {
		GETATTR3resok resok;
	} GETATTR3res_u;
};
typedef struct GETATTR3res GETATTR3res;

enum time_how {
	DONT_CHANGE = 0,
	SET_TO_SERVER_TIME = 1,
	SET_TO_CLIENT_TIME = 2,
};
typedef enum time_how time_how;

struct set_mode3 {
	bool_t set_it;
	union {
		mode3 mode;
	} set_mode3_u;
};
typedef struct set_mode3 set_mode3;

struct set_uid3 {
	bool_t set_it;
	union {
		uid3 uid;
	} set_uid3_u;
};
typedef struct set_uid3 set_uid3;

struct set_gid3 {
	bool_t set_it;
	union {
		gid3 gid;
	} set_gid3_u;
};
typedef struct set_gid3 set_gid3;

struct set_size3 {
	bool_t set_it;
	union {
		size3 size;
	} set_size3_u;
};
typedef struct set_size3 set_size3;

struct set_atime {
	time_how set_it;
	union {
		nfstime3 atime;
	} set_atime_u;
};
typedef struct set_atime set_atime;

struct set_mtime {
	time_how set_it;
	union {
		nfstime3 mtime;
	} set_mtime_u;
};
typedef struct set_mtime set_mtime;

struct sattr3 {
	set_mode3 mode;
	set_uid3 uid;
	set_gid3 gid;
	set_size3 size;
	set_atime atime;
	set_mtime mtime;
};
typedef struct sattr3 sattr3;

enum createmode3 {
	UNCHECKED = 0,
	GUARDED = 1,
	EXCLUSIVE = 2,
};
typedef enum createmode3 createmode3;

typedef char createverf3[NFS3_CREATEVERFSIZE];

struct createhow3 {
	createmode3 mode;
	union {
		sattr3 obj_attributes;
		sattr3 g_obj_attributes;
		createverf3 verf;
	} createhow3_u;
};
typedef struct createhow3 createhow3;

struct CREATE3args {
	diropargs3 where;
	createhow3 how;
};
typedef struct CREATE3args CREATE3args;

struct post_op_fh3 {
	bool_t handle_follows;
	union {
		nfs_fh3 handle;
	} post_op_fh3_u;
};
typedef struct post_op_fh3 post_op_fh3;

struct CREATE3resok {
	post_op_fh3 obj;
	post_op_attr obj_attributes;
	wcc_data dir_wcc;
};
typedef struct CREATE3resok CREATE3resok;

struct CREATE3resfail {
	wcc_data dir_wcc;
};
typedef struct CREATE3resfail CREATE3resfail;

struct CREATE3res {
	nfsstat3 status;
	union {
		CREATE3resok resok;
		CREATE3resfail resfail;
	} CREATE3res_u;
};
typedef struct CREATE3res CREATE3res;

struct REMOVE3args {
	diropargs3 object;
};
typedef struct REMOVE3args REMOVE3args;

struct REMOVE3resok {
	wcc_data dir_wcc;
};
typedef struct REMOVE3resok REMOVE3resok;

struct REMOVE3resfail {
	wcc_data dir_wcc;
};
typedef struct REMOVE3resfail REMOVE3resfail;

struct REMOVE3res {
	nfsstat3 status;
	union {
		REMOVE3resok resok;
		REMOVE3resfail resfail;
	} REMOVE3res_u;
};
typedef struct REMOVE3res REMOVE3res;

struct READ3args {
	nfs_fh3 file;
	offset3 offset;
	count3 count;
};
typedef struct READ3args READ3args;

struct READ3resok {
	post_op_attr file_attributes;
	count3 count;
	bool_t eof;
	struct {
		u_int data_len;
		char *data_val;
	} data;
};
typedef struct READ3resok READ3resok;

struct READ3resfail {
	post_op_attr file_attributes;
};
typedef struct READ3resfail READ3resfail;

struct READ3res {
	nfsstat3 status;
	union {
		READ3resok resok;
		READ3resfail resfail;
	} READ3res_u;
};
typedef struct READ3res READ3res;
#define FSF3_LINK 0x0001
#define FSF3_SYMLINK 0x0002
#define FSF3_HOMOGENEOUS 0x0008
#define FSF3_CANSETTIME 0x0010

struct FSINFO3args {
	nfs_fh3 fsroot;
};
typedef struct FSINFO3args FSINFO3args;

struct FSINFO3resok {
	post_op_attr obj_attributes;
	u_int rtmax;
	u_int rtpref;
	u_int rtmult;
	u_int wtmax;
	u_int wtpref;
	u_int wtmult;
	u_int dtpref;
	size3 maxfilesize;
	nfstime3 time_delta;
	u_int properties;
};
typedef struct FSINFO3resok FSINFO3resok;

struct FSINFO3resfail {
	post_op_attr obj_attributes;
};
typedef struct FSINFO3resfail FSINFO3resfail;

struct FSINFO3res {
	nfsstat3 status;
	union {
		FSINFO3resok resok;
		FSINFO3resfail resfail;
	} FSINFO3res_u;
};
typedef struct FSINFO3res FSINFO3res;

struct FSSTAT3args {
	nfs_fh3 fsroot;
};
typedef struct FSSTAT3args FSSTAT3args;

struct FSSTAT3resok {
	post_op_attr obj_attributes;
	size3 tbytes;
	size3 fbytes;
	size3 abytes;
	size3 tfiles;
	size3 ffiles;
	size3 afiles;
	u_int invarsec;
};
typedef struct FSSTAT3resok FSSTAT3resok;

struct FSSTAT3resfail {
	post_op_attr obj_attributes;
};
typedef struct FSSTAT3resfail FSSTAT3resfail;

struct FSSTAT3res {
	nfsstat3 status;
	union {
		FSSTAT3resok resok;
		FSSTAT3resfail resfail;
	} FSSTAT3res_u;
};
typedef struct FSSTAT3res FSSTAT3res;

struct PATHCONF3args {
	nfs_fh3 object;
};
typedef struct PATHCONF3args PATHCONF3args;

struct PATHCONF3resok {
	post_op_attr obj_attributes;
	u_int linkmax;
	u_int name_max;
	bool_t no_trunc;
	bool_t chown_restricted;
	bool_t case_insensitive;
	bool_t case_preserving;
};
typedef struct PATHCONF3resok PATHCONF3resok;

struct PATHCONF3resfail {
	post_op_attr obj_attributes;
};
typedef struct PATHCONF3resfail PATHCONF3resfail;

struct PATHCONF3res {
	nfsstat3 status;
	union {
		PATHCONF3resok resok;
		PATHCONF3resfail resfail;
	} PATHCONF3res_u;
};
typedef struct PATHCONF3res PATHCONF3res;

typedef char *nfspath3;

struct symlinkdata3 {
	sattr3 symlink_attributes;
	nfspath3 symlink_data;
};
typedef struct symlinkdata3 symlinkdata3;

struct SYMLINK3args {
	diropargs3 where;
	symlinkdata3 symlink;
};
typedef struct SYMLINK3args SYMLINK3args;

struct SYMLINK3resok {
	post_op_fh3 obj;
	post_op_attr obj_attributes;
	wcc_data dir_wcc;
};
typedef struct SYMLINK3resok SYMLINK3resok;

struct SYMLINK3resfail {
	wcc_data dir_wcc;
};
typedef struct SYMLINK3resfail SYMLINK3resfail;

struct SYMLINK3res {
	nfsstat3 status;
	union {
		SYMLINK3resok resok;
		SYMLINK3resfail resfail;
	} SYMLINK3res_u;
};
typedef struct SYMLINK3res SYMLINK3res;

struct READLINK3args {
	nfs_fh3 symlink;
};
typedef struct READLINK3args READLINK3args;

struct READLINK3resok {
	post_op_attr symlink_attributes;
	nfspath3 data;
};
typedef struct READLINK3resok READLINK3resok;

struct READLINK3resfail {
	post_op_attr symlink_attributes;
};
typedef struct READLINK3resfail READLINK3resfail;

struct READLINK3res {
	nfsstat3 status;
	union {
		READLINK3resok resok;
		READLINK3resfail resfail;
	} READLINK3res_u;
};
typedef struct READLINK3res READLINK3res;

struct devicedata3 {
	sattr3 dev_attributes;
	specdata3 spec;
};
typedef struct devicedata3 devicedata3;

struct mknoddata3 {
	ftype3 type;
	union {
		devicedata3 chr_device;
		devicedata3 blk_device;
		sattr3 sock_attributes;
		sattr3 pipe_attributes;
	} mknoddata3_u;
};
typedef struct mknoddata3 mknoddata3;

struct MKNOD3args {
	diropargs3 where;
	mknoddata3 what;
};
typedef struct MKNOD3args MKNOD3args;

struct MKNOD3resok {
	post_op_fh3 obj;
	post_op_attr obj_attributes;
	wcc_data dir_wcc;
};
typedef struct MKNOD3resok MKNOD3resok;

struct MKNOD3resfail {
	wcc_data dir_wcc;
};
typedef struct MKNOD3resfail MKNOD3resfail;

struct MKNOD3res {
	nfsstat3 status;
	union {
		MKNOD3resok resok;
		MKNOD3resfail resfail;
	} MKNOD3res_u;
};
typedef struct MKNOD3res MKNOD3res;

struct MKDIR3args {
	diropargs3 where;
	sattr3 attributes;
};
typedef struct MKDIR3args MKDIR3args;

struct MKDIR3resok {
	post_op_fh3 obj;
	post_op_attr obj_attributes;
	wcc_data dir_wcc;
};
typedef struct MKDIR3resok MKDIR3resok;

struct MKDIR3resfail {
	wcc_data dir_wcc;
};
typedef struct MKDIR3resfail MKDIR3resfail;

struct MKDIR3res {
	nfsstat3 status;
	union {
		MKDIR3resok resok;
		MKDIR3resfail resfail;
	} MKDIR3res_u;
};
typedef struct MKDIR3res MKDIR3res;

struct RMDIR3args {
	diropargs3 object;
};
typedef struct RMDIR3args RMDIR3args;

struct RMDIR3resok {
	wcc_data dir_wcc;
};
typedef struct RMDIR3resok RMDIR3resok;

struct RMDIR3resfail {
	wcc_data dir_wcc;
};
typedef struct RMDIR3resfail RMDIR3resfail;

struct RMDIR3res {
	nfsstat3 status;
	union {
		RMDIR3resok resok;
		RMDIR3resfail resfail;
	} RMDIR3res_u;
};
typedef struct RMDIR3res RMDIR3res;

struct RENAME3args {
	diropargs3 from;
	diropargs3 to;
};
typedef struct RENAME3args RENAME3args;

struct RENAME3resok {
	wcc_data fromdir_wcc;
	wcc_data todir_wcc;
};
typedef struct RENAME3resok RENAME3resok;

struct RENAME3resfail {
	wcc_data fromdir_wcc;
	wcc_data todir_wcc;
};
typedef struct RENAME3resfail RENAME3resfail;

struct RENAME3res {
	nfsstat3 status;
	union {
		RENAME3resok resok;
		RENAME3resfail resfail;
	} RENAME3res_u;
};
typedef struct RENAME3res RENAME3res;

struct READDIRPLUS3args {
	nfs_fh3 dir;
	cookie3 cookie;
	cookieverf3 cookieverf;
	count3 dircount;
	count3 maxcount;
};
typedef struct READDIRPLUS3args READDIRPLUS3args;

struct entryplus3 {
	fileid3 fileid;
	filename3 name;
	cookie3 cookie;
	post_op_attr name_attributes;
	post_op_fh3 name_handle;
	struct entryplus3 *nextentry;
};
typedef struct entryplus3 entryplus3;

struct dirlistplus3 {
	entryplus3 *entries;
	bool_t eof;
};
typedef struct dirlistplus3 dirlistplus3;

struct READDIRPLUS3resok {
	post_op_attr dir_attributes;
	cookieverf3 cookieverf;
	dirlistplus3 reply;
};
typedef struct READDIRPLUS3resok READDIRPLUS3resok;

struct READDIRPLUS3resfail {
	post_op_attr dir_attributes;
};
typedef struct READDIRPLUS3resfail READDIRPLUS3resfail;

struct READDIRPLUS3res {
	nfsstat3 status;
	union {
		READDIRPLUS3resok resok;
		READDIRPLUS3resfail resfail;
	} READDIRPLUS3res_u;
};
typedef struct READDIRPLUS3res READDIRPLUS3res;

struct READDIR3args {
	nfs_fh3 dir;
	cookie3 cookie;
	cookieverf3 cookieverf;
	count3 count;
};
typedef struct READDIR3args READDIR3args;

struct entry3 {
	fileid3 fileid;
	filename3 name;
	cookie3 cookie;
	struct entry3 *nextentry;
};
typedef struct entry3 entry3;

struct dirlist3 {
	entry3 *entries;
	bool_t eof;
};
typedef struct dirlist3 dirlist3;

struct READDIR3resok {
	post_op_attr dir_attributes;
	cookieverf3 cookieverf;
	dirlist3 reply;
};
typedef struct READDIR3resok READDIR3resok;

struct READDIR3resfail {
	post_op_attr dir_attributes;
};
typedef struct READDIR3resfail READDIR3resfail;

struct READDIR3res {
	nfsstat3 status;
	union {
		READDIR3resok resok;
		READDIR3resfail resfail;
	} READDIR3res_u;
};
typedef struct READDIR3res READDIR3res;

struct LINK3args {
	nfs_fh3 file;
	diropargs3 link;
};
typedef struct LINK3args LINK3args;

struct LINK3resok {
	post_op_attr file_attributes;
	wcc_data linkdir_wcc;
};
typedef struct LINK3resok LINK3resok;

struct LINK3resfail {
	post_op_attr file_attributes;
	wcc_data linkdir_wcc;
};
typedef struct LINK3resfail LINK3resfail;

struct LINK3res {
	nfsstat3 status;
	union {
		LINK3resok resok;
		LINK3resfail resfail;
	} LINK3res_u;
};
typedef struct LINK3res LINK3res;

struct sattrguard3 {
	bool_t check;
	union {
		nfstime3 obj_ctime;
	} sattrguard3_u;
};
typedef struct sattrguard3 sattrguard3;

struct SETATTR3args {
	nfs_fh3 object;
	sattr3 new_attributes;
	sattrguard3 guard;
};
typedef struct SETATTR3args SETATTR3args;

struct SETATTR3resok {
	wcc_data obj_wcc;
};
typedef struct SETATTR3resok SETATTR3resok;

struct SETATTR3resfail {
	wcc_data obj_wcc;
};
typedef struct SETATTR3resfail SETATTR3resfail;

struct SETATTR3res {
	nfsstat3 status;
	union {
		SETATTR3resok resok;
		SETATTR3resfail resfail;
	} SETATTR3res_u;
};
typedef struct SETATTR3res SETATTR3res;

enum nfsacl_type {
	NFSACL_TYPE_USER_OBJ = 0x0001,
	NFSACL_TYPE_USER = 0x0002,
	NFSACL_TYPE_GROUP_OBJ = 0x0004,
	NFSACL_TYPE_GROUP = 0x0008,
	NFSACL_TYPE_CLASS_OBJ = 0x0010,
	NFSACL_TYPE_CLASS = 0x0020,
	NFSACL_TYPE_DEFAULT = 0x1000,
	NFSACL_TYPE_DEFAULT_USER_OBJ = 0x1001,
	NFSACL_TYPE_DEFAULT_USER = 0x1002,
	NFSACL_TYPE_DEFAULT_GROUP_OBJ = 0x1004,
	NFSACL_TYPE_DEFAULT_GROUP = 0x1008,
	NFSACL_TYPE_DEFAULT_CLASS_OBJ = 0x1010,
	NFSACL_TYPE_DEFAULT_OTHER_OBJ = 0x1020,
};
typedef enum nfsacl_type nfsacl_type;
#define NFSACL_PERM_READ 0x04
#define NFSACL_PERM_WRITE 0x02
#define NFSACL_PERM_EXEC 0x01

struct nfsacl_ace {
	enum nfsacl_type type;
	u_int id;
	u_int perm;
};
typedef struct nfsacl_ace nfsacl_ace;
#define NFSACL_MASK_ACL_ENTRY 0x0001
#define NFSACL_MASK_ACL_COUNT 0x0002
#define NFSACL_MASK_ACL_DEFAULT_ENTRY 0x0004
#define NFSACL_MASK_ACL_DEFAULT_COUNT 0x0008

struct GETACL3args {
	nfs_fh3 dir;
	u_int mask;
};
typedef struct GETACL3args GETACL3args;

struct GETACL3resok {
	post_op_attr attr;
	u_int mask;
	u_int ace_count;
	struct {
		u_int ace_len;
		struct nfsacl_ace *ace_val;
	} ace;
	u_int default_ace_count;
	struct {
		u_int default_ace_len;
		struct nfsacl_ace *default_ace_val;
	} default_ace;
};
typedef struct GETACL3resok GETACL3resok;

struct GETACL3res {
	nfsstat3 status;
	union {
		GETACL3resok resok;
	} GETACL3res_u;
};
typedef struct GETACL3res GETACL3res;

struct SETACL3args {
	nfs_fh3 dir;
	u_int mask;
	u_int ace_count;
	struct {
		u_int ace_len;
		struct nfsacl_ace *ace_val;
	} ace;
	u_int default_ace_count;
	struct {
		u_int default_ace_len;
		struct nfsacl_ace *default_ace_val;
	} default_ace;
};
typedef struct SETACL3args SETACL3args;

struct SETACL3resok {
	post_op_attr attr;
};
typedef struct SETACL3resok SETACL3resok;

struct SETACL3res {
	nfsstat3 status;
	union {
		SETACL3resok resok;
	} SETACL3res_u;
};
typedef struct SETACL3res SETACL3res;

#define NFS_PROGRAM 100003
#define NFS_V3 3

#if defined(__STDC__) || defined(__cplusplus)
#define NFS3_NULL 0
extern  void * nfs3_null_3(void *, CLIENT *);
extern  void * nfs3_null_3_svc(void *, struct svc_req *);
#define NFS3_GETATTR 1
extern  GETATTR3res * nfs3_getattr_3(GETATTR3args *, CLIENT *);
extern  GETATTR3res * nfs3_getattr_3_svc(GETATTR3args *, struct svc_req *);
#define NFS3_SETATTR 2
extern  SETATTR3res * nfs3_setattr_3(SETATTR3args *, CLIENT *);
extern  SETATTR3res * nfs3_setattr_3_svc(SETATTR3args *, struct svc_req *);
#define NFS3_LOOKUP 3
extern  LOOKUP3res * nfs3_lookup_3(LOOKUP3args *, CLIENT *);
extern  LOOKUP3res * nfs3_lookup_3_svc(LOOKUP3args *, struct svc_req *);
#define NFS3_ACCESS 4
extern  ACCESS3res * nfs3_access_3(ACCESS3args *, CLIENT *);
extern  ACCESS3res * nfs3_access_3_svc(ACCESS3args *, struct svc_req *);
#define NFS3_READLINK 5
extern  READLINK3res * nfs3_readlink_3(READLINK3args *, CLIENT *);
extern  READLINK3res * nfs3_readlink_3_svc(READLINK3args *, struct svc_req *);
#define NFS3_READ 6
extern  READ3res * nfs3_read_3(READ3args *, CLIENT *);
extern  READ3res * nfs3_read_3_svc(READ3args *, struct svc_req *);
#define NFS3_WRITE 7
extern  WRITE3res * nfs3_write_3(WRITE3args *, CLIENT *);
extern  WRITE3res * nfs3_write_3_svc(WRITE3args *, struct svc_req *);
#define NFS3_CREATE 8
extern  CREATE3res * nfs3_create_3(CREATE3args *, CLIENT *);
extern  CREATE3res * nfs3_create_3_svc(CREATE3args *, struct svc_req *);
#define NFS3_MKDIR 9
extern  MKDIR3res * nfs3_mkdir_3(MKDIR3args *, CLIENT *);
extern  MKDIR3res * nfs3_mkdir_3_svc(MKDIR3args *, struct svc_req *);
#define NFS3_SYMLINK 10
extern  SYMLINK3res * nfs3_symlink_3(SYMLINK3args *, CLIENT *);
extern  SYMLINK3res * nfs3_symlink_3_svc(SYMLINK3args *, struct svc_req *);
#define NFS3_MKNOD 11
extern  MKNOD3res * nfs3_mknod_3(MKNOD3args *, CLIENT *);
extern  MKNOD3res * nfs3_mknod_3_svc(MKNOD3args *, struct svc_req *);
#define NFS3_REMOVE 12
extern  REMOVE3res * nfs3_remove_3(REMOVE3args *, CLIENT *);
extern  REMOVE3res * nfs3_remove_3_svc(REMOVE3args *, struct svc_req *);
#define NFS3_RMDIR 13
extern  RMDIR3res * nfs3_rmdir_3(RMDIR3args *, CLIENT *);
extern  RMDIR3res * nfs3_rmdir_3_svc(RMDIR3args *, struct svc_req *);
#define NFS3_RENAME 14
extern  RENAME3res * nfs3_rename_3(RENAME3args *, CLIENT *);
extern  RENAME3res * nfs3_rename_3_svc(RENAME3args *, struct svc_req *);
#define NFS3_LINK 15
extern  LINK3res * nfs3_link_3(LINK3args *, CLIENT *);
extern  LINK3res * nfs3_link_3_svc(LINK3args *, struct svc_req *);
#define NFS3_READDIR 16
extern  READDIR3res * nfs3_readdir_3(READDIR3args *, CLIENT *);
extern  READDIR3res * nfs3_readdir_3_svc(READDIR3args *, struct svc_req *);
#define NFS3_READDIRPLUS 17
extern  READDIRPLUS3res * nfs3_readdirplus_3(READDIRPLUS3args *, CLIENT *);
extern  READDIRPLUS3res * nfs3_readdirplus_3_svc(READDIRPLUS3args *, struct svc_req *);
#define NFS3_FSSTAT 18
extern  FSSTAT3res * nfs3_fsstat_3(FSSTAT3args *, CLIENT *);
extern  FSSTAT3res * nfs3_fsstat_3_svc(FSSTAT3args *, struct svc_req *);
#define NFS3_FSINFO 19
extern  FSINFO3res * nfs3_fsinfo_3(FSINFO3args *, CLIENT *);
extern  FSINFO3res * nfs3_fsinfo_3_svc(FSINFO3args *, struct svc_req *);
#define NFS3_PATHCONF 20
extern  PATHCONF3res * nfs3_pathconf_3(PATHCONF3args *, CLIENT *);
extern  PATHCONF3res * nfs3_pathconf_3_svc(PATHCONF3args *, struct svc_req *);
#define NFS3_COMMIT 21
extern  COMMIT3res * nfs3_commit_3(COMMIT3args *, CLIENT *);
extern  COMMIT3res * nfs3_commit_3_svc(COMMIT3args *, struct svc_req *);
extern int nfs_program_3_freeresult (SVCXPRT *, zdrproc_t, caddr_t);

#else /* K&R C */
#define NFS3_NULL 0
extern  void * nfs3_null_3();
extern  void * nfs3_null_3_svc();
#define NFS3_GETATTR 1
extern  GETATTR3res * nfs3_getattr_3();
extern  GETATTR3res * nfs3_getattr_3_svc();
#define NFS3_SETATTR 2
extern  SETATTR3res * nfs3_setattr_3();
extern  SETATTR3res * nfs3_setattr_3_svc();
#define NFS3_LOOKUP 3
extern  LOOKUP3res * nfs3_lookup_3();
extern  LOOKUP3res * nfs3_lookup_3_svc();
#define NFS3_ACCESS 4
extern  ACCESS3res * nfs3_access_3();
extern  ACCESS3res * nfs3_access_3_svc();
#define NFS3_READLINK 5
extern  READLINK3res * nfs3_readlink_3();
extern  READLINK3res * nfs3_readlink_3_svc();
#define NFS3_READ 6
extern  READ3res * nfs3_read_3();
extern  READ3res * nfs3_read_3_svc();
#define NFS3_WRITE 7
extern  WRITE3res * nfs3_write_3();
extern  WRITE3res * nfs3_write_3_svc();
#define NFS3_CREATE 8
extern  CREATE3res * nfs3_create_3();
extern  CREATE3res * nfs3_create_3_svc();
#define NFS3_MKDIR 9
extern  MKDIR3res * nfs3_mkdir_3();
extern  MKDIR3res * nfs3_mkdir_3_svc();
#define NFS3_SYMLINK 10
extern  SYMLINK3res * nfs3_symlink_3();
extern  SYMLINK3res * nfs3_symlink_3_svc();
#define NFS3_MKNOD 11
extern  MKNOD3res * nfs3_mknod_3();
extern  MKNOD3res * nfs3_mknod_3_svc();
#define NFS3_REMOVE 12
extern  REMOVE3res * nfs3_remove_3();
extern  REMOVE3res * nfs3_remove_3_svc();
#define NFS3_RMDIR 13
extern  RMDIR3res * nfs3_rmdir_3();
extern  RMDIR3res * nfs3_rmdir_3_svc();
#define NFS3_RENAME 14
extern  RENAME3res * nfs3_rename_3();
extern  RENAME3res * nfs3_rename_3_svc();
#define NFS3_LINK 15
extern  LINK3res * nfs3_link_3();
extern  LINK3res * nfs3_link_3_svc();
#define NFS3_READDIR 16
extern  READDIR3res * nfs3_readdir_3();
extern  READDIR3res * nfs3_readdir_3_svc();
#define NFS3_READDIRPLUS 17
extern  READDIRPLUS3res * nfs3_readdirplus_3();
extern  READDIRPLUS3res * nfs3_readdirplus_3_svc();
#define NFS3_FSSTAT 18
extern  FSSTAT3res * nfs3_fsstat_3();
extern  FSSTAT3res * nfs3_fsstat_3_svc();
#define NFS3_FSINFO 19
extern  FSINFO3res * nfs3_fsinfo_3();
extern  FSINFO3res * nfs3_fsinfo_3_svc();
#define NFS3_PATHCONF 20
extern  PATHCONF3res * nfs3_pathconf_3();
extern  PATHCONF3res * nfs3_pathconf_3_svc();
#define NFS3_COMMIT 21
extern  COMMIT3res * nfs3_commit_3();
extern  COMMIT3res * nfs3_commit_3_svc();
extern int nfs_program_3_freeresult ();
#endif /* K&R C */

#define NFSACL_PROGRAM 100227
#define NFSACL_V3 3

#if defined(__STDC__) || defined(__cplusplus)
#define NFSACL3_NULL 0
extern  void * nfsacl3_null_3(void *, CLIENT *);
extern  void * nfsacl3_null_3_svc(void *, struct svc_req *);
#define NFSACL3_GETACL 1
extern  GETACL3res * nfsacl3_getacl_3(GETACL3args *, CLIENT *);
extern  GETACL3res * nfsacl3_getacl_3_svc(GETACL3args *, struct svc_req *);
#define NFSACL3_SETACL 2
extern  SETACL3res * nfsacl3_setacl_3(SETACL3args *, CLIENT *);
extern  SETACL3res * nfsacl3_setacl_3_svc(SETACL3args *, struct svc_req *);
extern int nfsacl_program_3_freeresult (SVCXPRT *, zdrproc_t, caddr_t);

#else /* K&R C */
#define NFSACL3_NULL 0
extern  void * nfsacl3_null_3();
extern  void * nfsacl3_null_3_svc();
#define NFSACL3_GETACL 1
extern  GETACL3res * nfsacl3_getacl_3();
extern  GETACL3res * nfsacl3_getacl_3_svc();
#define NFSACL3_SETACL 2
extern  SETACL3res * nfsacl3_setacl_3();
extern  SETACL3res * nfsacl3_setacl_3_svc();
extern int nfsacl_program_3_freeresult ();
#endif /* K&R C */

/* the zdr functions */

#if defined(__STDC__) || defined(__cplusplus)
extern  bool_t zdr_cookieverf3 (ZDR *, cookieverf3);
extern  bool_t zdr_uint64 (ZDR *, uint64*);
extern  bool_t zdr_cookie3 (ZDR *, cookie3*);
extern  bool_t zdr_nfs_fh3 (ZDR *, nfs_fh3*);
extern  bool_t zdr_filename3 (ZDR *, filename3*);
extern  bool_t zdr_diropargs3 (ZDR *, diropargs3*);
extern  bool_t zdr_ftype3 (ZDR *, ftype3*);
extern  bool_t zdr_mode3 (ZDR *, mode3*);
extern  bool_t zdr_uid3 (ZDR *, uid3*);
extern  bool_t zdr_gid3 (ZDR *, gid3*);
extern  bool_t zdr_size3 (ZDR *, size3*);
extern  bool_t zdr_fileid3 (ZDR *, fileid3*);
extern  bool_t zdr_specdata3 (ZDR *, specdata3*);
extern  bool_t zdr_nfstime3 (ZDR *, nfstime3*);
extern  bool_t zdr_fattr3 (ZDR *, fattr3*);
extern  bool_t zdr_post_op_attr (ZDR *, post_op_attr*);
extern  bool_t zdr_nfsstat3 (ZDR *, nfsstat3*);
extern  bool_t zdr_stable_how (ZDR *, stable_how*);
extern  bool_t zdr_offset3 (ZDR *, offset3*);
extern  bool_t zdr_count3 (ZDR *, count3*);
extern  bool_t zdr_wcc_attr (ZDR *, wcc_attr*);
extern  bool_t zdr_pre_op_attr (ZDR *, pre_op_attr*);
extern  bool_t zdr_wcc_data (ZDR *, wcc_data*);
extern  bool_t zdr_WRITE3args (ZDR *, WRITE3args*);
extern  bool_t zdr_writeverf3 (ZDR *, writeverf3);
extern  bool_t zdr_WRITE3resok (ZDR *, WRITE3resok*);
extern  bool_t zdr_WRITE3resfail (ZDR *, WRITE3resfail*);
extern  bool_t zdr_WRITE3res (ZDR *, WRITE3res*);
extern  bool_t zdr_LOOKUP3args (ZDR *, LOOKUP3args*);
extern  bool_t zdr_LOOKUP3resok (ZDR *, LOOKUP3resok*);
extern  bool_t zdr_LOOKUP3resfail (ZDR *, LOOKUP3resfail*);
extern  bool_t zdr_LOOKUP3res (ZDR *, LOOKUP3res*);
extern  bool_t zdr_COMMIT3args (ZDR *, COMMIT3args*);
extern  bool_t zdr_COMMIT3resok (ZDR *, COMMIT3resok*);
extern  bool_t zdr_COMMIT3resfail (ZDR *, COMMIT3resfail*);
extern  bool_t zdr_COMMIT3res (ZDR *, COMMIT3res*);
extern  bool_t zdr_ACCESS3args (ZDR *, ACCESS3args*);
extern  bool_t zdr_ACCESS3resok (ZDR *, ACCESS3resok*);
extern  bool_t zdr_ACCESS3resfail (ZDR *, ACCESS3resfail*);
extern  bool_t zdr_ACCESS3res (ZDR *, ACCESS3res*);
extern  bool_t zdr_GETATTR3args (ZDR *, GETATTR3args*);
extern  bool_t zdr_GETATTR3resok (ZDR *, GETATTR3resok*);
extern  bool_t zdr_GETATTR3res (ZDR *, GETATTR3res*);
extern  bool_t zdr_time_how (ZDR *, time_how*);
extern  bool_t zdr_set_mode3 (ZDR *, set_mode3*);
extern  bool_t zdr_set_uid3 (ZDR *, set_uid3*);
extern  bool_t zdr_set_gid3 (ZDR *, set_gid3*);
extern  bool_t zdr_set_size3 (ZDR *, set_size3*);
extern  bool_t zdr_set_atime (ZDR *, set_atime*);
extern  bool_t zdr_set_mtime (ZDR *, set_mtime*);
extern  bool_t zdr_sattr3 (ZDR *, sattr3*);
extern  bool_t zdr_createmode3 (ZDR *, createmode3*);
extern  bool_t zdr_createverf3 (ZDR *, createverf3);
extern  bool_t zdr_createhow3 (ZDR *, createhow3*);
extern  bool_t zdr_CREATE3args (ZDR *, CREATE3args*);
extern  bool_t zdr_post_op_fh3 (ZDR *, post_op_fh3*);
extern  bool_t zdr_CREATE3resok (ZDR *, CREATE3resok*);
extern  bool_t zdr_CREATE3resfail (ZDR *, CREATE3resfail*);
extern  bool_t zdr_CREATE3res (ZDR *, CREATE3res*);
extern  bool_t zdr_REMOVE3args (ZDR *, REMOVE3args*);
extern  bool_t zdr_REMOVE3resok (ZDR *, REMOVE3resok*);
extern  bool_t zdr_REMOVE3resfail (ZDR *, REMOVE3resfail*);
extern  bool_t zdr_REMOVE3res (ZDR *, REMOVE3res*);
extern  bool_t zdr_READ3args (ZDR *, READ3args*);
extern  bool_t zdr_READ3resok (ZDR *, READ3resok*);
extern  bool_t zdr_READ3resfail (ZDR *, READ3resfail*);
extern  bool_t zdr_READ3res (ZDR *, READ3res*);
extern  bool_t zdr_FSINFO3args (ZDR *, FSINFO3args*);
extern  bool_t zdr_FSINFO3resok (ZDR *, FSINFO3resok*);
extern  bool_t zdr_FSINFO3resfail (ZDR *, FSINFO3resfail*);
extern  bool_t zdr_FSINFO3res (ZDR *, FSINFO3res*);
extern  bool_t zdr_FSSTAT3args (ZDR *, FSSTAT3args*);
extern  bool_t zdr_FSSTAT3resok (ZDR *, FSSTAT3resok*);
extern  bool_t zdr_FSSTAT3resfail (ZDR *, FSSTAT3resfail*);
extern  bool_t zdr_FSSTAT3res (ZDR *, FSSTAT3res*);
extern  bool_t zdr_PATHCONF3args (ZDR *, PATHCONF3args*);
extern  bool_t zdr_PATHCONF3resok (ZDR *, PATHCONF3resok*);
extern  bool_t zdr_PATHCONF3resfail (ZDR *, PATHCONF3resfail*);
extern  bool_t zdr_PATHCONF3res (ZDR *, PATHCONF3res*);
extern  bool_t zdr_nfspath3 (ZDR *, nfspath3*);
extern  bool_t zdr_symlinkdata3 (ZDR *, symlinkdata3*);
extern  bool_t zdr_SYMLINK3args (ZDR *, SYMLINK3args*);
extern  bool_t zdr_SYMLINK3resok (ZDR *, SYMLINK3resok*);
extern  bool_t zdr_SYMLINK3resfail (ZDR *, SYMLINK3resfail*);
extern  bool_t zdr_SYMLINK3res (ZDR *, SYMLINK3res*);
extern  bool_t zdr_READLINK3args (ZDR *, READLINK3args*);
extern  bool_t zdr_READLINK3resok (ZDR *, READLINK3resok*);
extern  bool_t zdr_READLINK3resfail (ZDR *, READLINK3resfail*);
extern  bool_t zdr_READLINK3res (ZDR *, READLINK3res*);
extern  bool_t zdr_devicedata3 (ZDR *, devicedata3*);
extern  bool_t zdr_mknoddata3 (ZDR *, mknoddata3*);
extern  bool_t zdr_MKNOD3args (ZDR *, MKNOD3args*);
extern  bool_t zdr_MKNOD3resok (ZDR *, MKNOD3resok*);
extern  bool_t zdr_MKNOD3resfail (ZDR *, MKNOD3resfail*);
extern  bool_t zdr_MKNOD3res (ZDR *, MKNOD3res*);
extern  bool_t zdr_MKDIR3args (ZDR *, MKDIR3args*);
extern  bool_t zdr_MKDIR3resok (ZDR *, MKDIR3resok*);
extern  bool_t zdr_MKDIR3resfail (ZDR *, MKDIR3resfail*);
extern  bool_t zdr_MKDIR3res (ZDR *, MKDIR3res*);
extern  bool_t zdr_RMDIR3args (ZDR *, RMDIR3args*);
extern  bool_t zdr_RMDIR3resok (ZDR *, RMDIR3resok*);
extern  bool_t zdr_RMDIR3resfail (ZDR *, RMDIR3resfail*);
extern  bool_t zdr_RMDIR3res (ZDR *, RMDIR3res*);
extern  bool_t zdr_RENAME3args (ZDR *, RENAME3args*);
extern  bool_t zdr_RENAME3resok (ZDR *, RENAME3resok*);
extern  bool_t zdr_RENAME3resfail (ZDR *, RENAME3resfail*);
extern  bool_t zdr_RENAME3res (ZDR *, RENAME3res*);
extern  bool_t zdr_READDIRPLUS3args (ZDR *, READDIRPLUS3args*);
extern  bool_t zdr_entryplus3 (ZDR *, entryplus3*);
extern  bool_t zdr_dirlistplus3 (ZDR *, dirlistplus3*);
extern  bool_t zdr_READDIRPLUS3resok (ZDR *, READDIRPLUS3resok*);
extern  bool_t zdr_READDIRPLUS3resfail (ZDR *, READDIRPLUS3resfail*);
extern  bool_t zdr_READDIRPLUS3res (ZDR *, READDIRPLUS3res*);
extern  bool_t zdr_READDIR3args (ZDR *, READDIR3args*);
extern  bool_t zdr_entry3 (ZDR *, entry3*);
extern  bool_t zdr_dirlist3 (ZDR *, dirlist3*);
extern  bool_t zdr_READDIR3resok (ZDR *, READDIR3resok*);
extern  bool_t zdr_READDIR3resfail (ZDR *, READDIR3resfail*);
extern  bool_t zdr_READDIR3res (ZDR *, READDIR3res*);
extern  bool_t zdr_LINK3args (ZDR *, LINK3args*);
extern  bool_t zdr_LINK3resok (ZDR *, LINK3resok*);
extern  bool_t zdr_LINK3resfail (ZDR *, LINK3resfail*);
extern  bool_t zdr_LINK3res (ZDR *, LINK3res*);
extern  bool_t zdr_sattrguard3 (ZDR *, sattrguard3*);
extern  bool_t zdr_SETATTR3args (ZDR *, SETATTR3args*);
extern  bool_t zdr_SETATTR3resok (ZDR *, SETATTR3resok*);
extern  bool_t zdr_SETATTR3resfail (ZDR *, SETATTR3resfail*);
extern  bool_t zdr_SETATTR3res (ZDR *, SETATTR3res*);
extern  bool_t zdr_nfsacl_type (ZDR *, nfsacl_type*);
extern  bool_t zdr_nfsacl_ace (ZDR *, nfsacl_ace*);
extern  bool_t zdr_GETACL3args (ZDR *, GETACL3args*);
extern  bool_t zdr_GETACL3resok (ZDR *, GETACL3resok*);
extern  bool_t zdr_GETACL3res (ZDR *, GETACL3res*);
extern  bool_t zdr_SETACL3args (ZDR *, SETACL3args*);
extern  bool_t zdr_SETACL3resok (ZDR *, SETACL3resok*);
extern  bool_t zdr_SETACL3res (ZDR *, SETACL3res*);

#else /* K&R C */
extern bool_t zdr_cookieverf3 ();
extern bool_t zdr_uint64 ();
extern bool_t zdr_cookie3 ();
extern bool_t zdr_nfs_fh3 ();
extern bool_t zdr_filename3 ();
extern bool_t zdr_diropargs3 ();
extern bool_t zdr_ftype3 ();
extern bool_t zdr_mode3 ();
extern bool_t zdr_uid3 ();
extern bool_t zdr_gid3 ();
extern bool_t zdr_size3 ();
extern bool_t zdr_fileid3 ();
extern bool_t zdr_specdata3 ();
extern bool_t zdr_nfstime3 ();
extern bool_t zdr_fattr3 ();
extern bool_t zdr_post_op_attr ();
extern bool_t zdr_nfsstat3 ();
extern bool_t zdr_stable_how ();
extern bool_t zdr_offset3 ();
extern bool_t zdr_count3 ();
extern bool_t zdr_wcc_attr ();
extern bool_t zdr_pre_op_attr ();
extern bool_t zdr_wcc_data ();
extern bool_t zdr_WRITE3args ();
extern bool_t zdr_writeverf3 ();
extern bool_t zdr_WRITE3resok ();
extern bool_t zdr_WRITE3resfail ();
extern bool_t zdr_WRITE3res ();
extern bool_t zdr_LOOKUP3args ();
extern bool_t zdr_LOOKUP3resok ();
extern bool_t zdr_LOOKUP3resfail ();
extern bool_t zdr_LOOKUP3res ();
extern bool_t zdr_COMMIT3args ();
extern bool_t zdr_COMMIT3resok ();
extern bool_t zdr_COMMIT3resfail ();
extern bool_t zdr_COMMIT3res ();
extern bool_t zdr_ACCESS3args ();
extern bool_t zdr_ACCESS3resok ();
extern bool_t zdr_ACCESS3resfail ();
extern bool_t zdr_ACCESS3res ();
extern bool_t zdr_GETATTR3args ();
extern bool_t zdr_GETATTR3resok ();
extern bool_t zdr_GETATTR3res ();
extern bool_t zdr_time_how ();
extern bool_t zdr_set_mode3 ();
extern bool_t zdr_set_uid3 ();
extern bool_t zdr_set_gid3 ();
extern bool_t zdr_set_size3 ();
extern bool_t zdr_set_atime ();
extern bool_t zdr_set_mtime ();
extern bool_t zdr_sattr3 ();
extern bool_t zdr_createmode3 ();
extern bool_t zdr_createverf3 ();
extern bool_t zdr_createhow3 ();
extern bool_t zdr_CREATE3args ();
extern bool_t zdr_post_op_fh3 ();
extern bool_t zdr_CREATE3resok ();
extern bool_t zdr_CREATE3resfail ();
extern bool_t zdr_CREATE3res ();
extern bool_t zdr_REMOVE3args ();
extern bool_t zdr_REMOVE3resok ();
extern bool_t zdr_REMOVE3resfail ();
extern bool_t zdr_REMOVE3res ();
extern bool_t zdr_READ3args ();
extern bool_t zdr_READ3resok ();
extern bool_t zdr_READ3resfail ();
extern bool_t zdr_READ3res ();
extern bool_t zdr_FSINFO3args ();
extern bool_t zdr_FSINFO3resok ();
extern bool_t zdr_FSINFO3resfail ();
extern bool_t zdr_FSINFO3res ();
extern bool_t zdr_FSSTAT3args ();
extern bool_t zdr_FSSTAT3resok ();
extern bool_t zdr_FSSTAT3resfail ();
extern bool_t zdr_FSSTAT3res ();
extern bool_t zdr_PATHCONF3args ();
extern bool_t zdr_PATHCONF3resok ();
extern bool_t zdr_PATHCONF3resfail ();
extern bool_t zdr_PATHCONF3res ();
extern bool_t zdr_nfspath3 ();
extern bool_t zdr_symlinkdata3 ();
extern bool_t zdr_SYMLINK3args ();
extern bool_t zdr_SYMLINK3resok ();
extern bool_t zdr_SYMLINK3resfail ();
extern bool_t zdr_SYMLINK3res ();
extern bool_t zdr_READLINK3args ();
extern bool_t zdr_READLINK3resok ();
extern bool_t zdr_READLINK3resfail ();
extern bool_t zdr_READLINK3res ();
extern bool_t zdr_devicedata3 ();
extern bool_t zdr_mknoddata3 ();
extern bool_t zdr_MKNOD3args ();
extern bool_t zdr_MKNOD3resok ();
extern bool_t zdr_MKNOD3resfail ();
extern bool_t zdr_MKNOD3res ();
extern bool_t zdr_MKDIR3args ();
extern bool_t zdr_MKDIR3resok ();
extern bool_t zdr_MKDIR3resfail ();
extern bool_t zdr_MKDIR3res ();
extern bool_t zdr_RMDIR3args ();
extern bool_t zdr_RMDIR3resok ();
extern bool_t zdr_RMDIR3resfail ();
extern bool_t zdr_RMDIR3res ();
extern bool_t zdr_RENAME3args ();
extern bool_t zdr_RENAME3resok ();
extern bool_t zdr_RENAME3resfail ();
extern bool_t zdr_RENAME3res ();
extern bool_t zdr_READDIRPLUS3args ();
extern bool_t zdr_entryplus3 ();
extern bool_t zdr_dirlistplus3 ();
extern bool_t zdr_READDIRPLUS3resok ();
extern bool_t zdr_READDIRPLUS3resfail ();
extern bool_t zdr_READDIRPLUS3res ();
extern bool_t zdr_READDIR3args ();
extern bool_t zdr_entry3 ();
extern bool_t zdr_dirlist3 ();
extern bool_t zdr_READDIR3resok ();
extern bool_t zdr_READDIR3resfail ();
extern bool_t zdr_READDIR3res ();
extern bool_t zdr_LINK3args ();
extern bool_t zdr_LINK3resok ();
extern bool_t zdr_LINK3resfail ();
extern bool_t zdr_LINK3res ();
extern bool_t zdr_sattrguard3 ();
extern bool_t zdr_SETATTR3args ();
extern bool_t zdr_SETATTR3resok ();
extern bool_t zdr_SETATTR3resfail ();
extern bool_t zdr_SETATTR3res ();
extern bool_t zdr_nfsacl_type ();
extern bool_t zdr_nfsacl_ace ();
extern bool_t zdr_GETACL3args ();
extern bool_t zdr_GETACL3resok ();
extern bool_t zdr_GETACL3res ();
extern bool_t zdr_SETACL3args ();
extern bool_t zdr_SETACL3resok ();
extern bool_t zdr_SETACL3res ();

#endif /* K&R C */

#ifdef __cplusplus
}
#endif

#endif /* !_NFS_H_RPCGEN */
